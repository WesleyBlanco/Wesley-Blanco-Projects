#This is the Music Cog for Walleye Bot.
#This cog allows Walleye Bot to play anything from a youtube search
#
#
#Last edited: August 4th, 2021
#
#
#Acknowledgement:
# This cog is heavily aided by a guide made by "Pawel Bes" on Youtube, as I
# am not well versed in voice commands to Discord bots


import discord
from discord.ext import commands
from youtube_dl import YoutubeDL

class music(commands.Cog):
    #oddly, in all my other cogs, I can use client consistently without an issue
    #however in this cog, if i use client i get errors regarding client not being initialized
    #This is why I used Pawel Bes' guide
    def __init__(self, bot):
        self.bot = bot

        #Setting a variable for if the bot is presently playing music
        self.is_playing = False

        # 2d array containing [song, channel] for outputting the queue and of course playing in order
        self.music_queue = []
        #Setting the youtube dl and FFMPEG options to their best settings
        self.YDL_OPTIONS = {'format': 'bestaudio', 'noplaylist':'True'}
        self.FFMPEG_OPTIONS = {'before_options': '-reconnect 1 -reconnect_streamed 1 -reconnect_delay_max 5', 'options': '-vn'}

        self.vc = ""

    #For searching youtube with an input from the user
    def search_yt(self, item):
        with YoutubeDL(self.YDL_OPTIONS) as ydl:
            try:
                #This attempts to find the important info for the queue
                info = ydl.extract_info("ytsearch:%s" % item, download=False)['entries'][0]
            except Exception:
                return False
        #This returns the info gathered from line 40 to the play command
        return {'source': info['formats'][0]['url'], 'title': info['title']}

    def play_next(self):
        if len(self.music_queue) > 0:#if the queue is greater than 0, theres something in the queue
            self.is_playing = True #Sets the player to playing music true

            m_url = self.music_queue[0][0]['source']

            #Removing the first item in the queue as its the presently being listened to song
            self.music_queue.pop(0)
            #Begin playing the next song in the queue, using the FFMPEG options, and calling the function again to keep
            #playing music if their is something in the queue
            self.vc.play(discord.FFmpegPCMAudio(m_url, **self.FFMPEG_OPTIONS), after=lambda e: self.play_next())
        else: #if there is nothing in the queue
            self.is_playing = False

    # This is for the first time the bot runs something from youtube
    async def play_music(self):
        if len(self.music_queue) > 0:
            self.is_playing = True

            m_url = self.music_queue[0][0]['source']

            #If the bot is not in a channel yet, this puts it into it.
            if self.vc == "" or not self.vc.is_connected() or self.vc == None:
                self.vc = await self.music_queue[0][1].connect()
            else:
                await self.vc.move_to(self.music_queue[0][1])

            print(self.music_queue)
            #remove the first element as it is playing
            self.music_queue.pop(0)

            self.vc.play(discord.FFmpegPCMAudio(m_url, **self.FFMPEG_OPTIONS), after=lambda e: self.play_next())
        else:
            self.is_playing = False

    #This is the primary function of this cog
    #This function connects to a voice channel, calls search_yt to find Content
    #And then it adds this to the queue. If it bot isnt already playing content, checked by the is_playing variable
    #then the bot will begin playing the content
    @commands.command(name="play", aliases=['p', 'P', 'Play'])
    async def p(self, ctx, *args):
        query = " ".join(args)

        voice_channel = ctx.author.voice.channel
        if voice_channel is None:
            #Bot will not run music if you arent in a voice channel to base the bot connection to.
            await ctx.send("You aren't in a voice channel. If you aren't in a voice channel, theres no reason for me to play anything")
        else:
            song = self.search_yt(query) #call search_yt to find the content
            if type(song) == type(True):
                #This wont work for playlists and for livestreams, so this has to be here to stop it from trying to add them to the queue
                await ctx.send("You know, Wes made this bot so its gonna fail sometimes. Whatever you searched for didn't work. Likely, it was a playlist link or a livestream that ruined it")
            else:
                self.music_queue.append([song, voice_channel])
                queueLength = len(self.music_queue)
                await ctx.send(f'{song["title"]} was added to the queue, at position {queueLength}')

                if self.is_playing == False: #Start playing things if it isnt already playing through play_next and play_music
                    await self.play_music()

    #This function returns the queue to the user
    @commands.command(name="queue", aliases=['q', 'Q'])
    async def q(self, ctx):
        retval = ""
        for i in range(0, len(self.music_queue)):
            retval += self.music_queue[i][0]['title'] + "\n"

        print(retval)
        if retval != "":
            await ctx.send(retval)
        else:
            await ctx.send("No music in queue")

    #This function skips the song that is presently playing, not the next song
    @commands.command(name="skip", aliases=['s', 'S'])
    async def skip(self, ctx):
        if self.vc != "" and self.vc:
            self.vc.stop()
            #try to play next in the queue if it exists
            await self.play_music()

    #for when the bot has gotten annoying enough to kick it out
    #this command will throw an error if the bot has not been in a voice channel
    #before the first time after a start up if you are calling it to leave and it isnt in a voice_channel
    #this is because it doesn't recongize self.vc as anything but a string until it has at least started one song
    @commands.command(name="leave", aliases=['l', 'L'])
    async def leave(self, ctx):
        if ctx.author.voice is None or not self.vc.is_connected():
            await ctx.send("I'm not in a channel that you can remove me from")
            return
        await ctx.voice_client.disconnect()


def setup(client):
    client.add_cog(music(client))
