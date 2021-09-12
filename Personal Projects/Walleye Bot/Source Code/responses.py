import discord
from discord.ext import commands

class responses(commands.Cog):

    def __init___(self, client):
        self.client = client

    @commands.command()
    @commands.has_permissions(manage_messages=True)
    async def purge(self, ctx, arg):
        try:
            fixer = int(arg) + 1
        except ValueError:
            ctx.send("Thats not a valid number")
            return
        await ctx.channel.purge(limit=fixer)

    #Commands for myself
    @commands.command(aliases=['walleye', 'wes', 'Wes'])
    async def Walleye(self, ctx):
        if ctx.author.id == 308931180244238336:
            await ctx.send("Hello creator")
        else:
            await ctx.send('Walleye is pretty cool yeah?')

    @commands.command(aliases=['logan'])
    async def Logan(self, ctx):
        if ctx.author.id == 277333197593903106:
            await ctx.send("Bro why you talking to yourself")
        else:
            await ctx.send("Sound board extrodinare")

    @commands.command(aliases=['jerry', 'Jeremy', 'jeremy'])
    async def Jerry(self, ctx):
        if ctx.author.id == 264192132791795723:
            await ctx.send("Did you know Pyro ball has 90% accuracy?")
        else:
            await ctx.send("He doesn't make the monkeys, he just sells them")

    @commands.command(aliases=['bryce', 'bigcat', 'BigCat'])
    async def Bryce(self, ctx):
            await ctx.send("Bryce loves Gambit")

    @commands.command(aliases=['zavala'])
    async def Zavala(self, ctx):
        await ctx.send("Whether we wanted it or not, we've stepped into a war with the Cabal on Mars. So let's get to taking out their command, one by one. Valus Ta'aurc. From what I can gather he commands the Siege Dancers from an Imperial Land Tank outside of Rubicon. He's well protected, but with the right team, we can punch through those defenses, take this beast out, and break their grip on Freehold")

    @commands.command(aliases=['steve'])
    async def Steve(self, ctx):
        if ctx.author.id == 296811349323808769:
            await ctx.send("I love my roommates")
        else:
            await ctx.send("Flawless Garden of Salvation anyone? No? Last wish?")

    @commands.command(aliases=['luther'])
    async def Luther(self, ctx):
        await ctx.send("Realm of the Mad God Exalt")

    @commands.command(aliases=['Brando', 'bubby', 'Bubby', 'brando', 'Brandon'])
    async def brandon(self, ctx):
        await ctx.send("Did somebody say bounties?")

    @commands.command(aliases=['luke'])
    async def Luke(self, ctx):
        if ctx.author.id == 203317975921459200:
            await ctx.send("Cracked 16 year old gamer")
        else:
            await ctx.send("Clan traitor")

    @commands.command(aliases=['grant', 'infernos', 'Infernos'])
    async def Grant(self, ctx):
        if ctx.author.id == 203317975921459200:
            await ctx.send("Infernos Garmin")
        else:
            await ctx.send("He is not a Titan, he is the bullet")

    @commands.command(aliases=['Mikey'])
    async def mikey(self, ctx):
        await ctx.send("Wardcliff coil is OP")

    @commands.command()
    async def pitter(self, ctx):
        await ctx.send("Pitter-patter let's get at 'er")

    @commands.command()
    async def help(self, ctx):
        helpEmbed = discord.Embed(
            title = "Walleye Bot",
            description = "This is a bot made by Walleye FT, also known as Wes",
            colour = discord.Colour.blue()
        )

        helpEmbed.set_footer(text= "Version 1.00, Release")
        helpEmbed.set_author(name = "Walleye FT", icon_url='https://cdn.discordapp.com/attachments/430182611814711299/867533105904615484/profilepic.jpg')
        helpEmbed.add_field(name="Help", value="This bot is for the use of Wes and his friends for jokes, discord moderation, Pokemon information gathering, and audio purposes")
        await ctx.send(embed=helpEmbed)

def setup(client):
    client.add_cog(responses(client))
