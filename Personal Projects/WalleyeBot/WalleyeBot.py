#Walleye Bot Main Driver
#This is the main Driver for Walleye bot that connects all the Cogs together
#This has very little programming in it, just drives the program really
#
#Last Updated: August 4th 2021

import discord
import os
import json
from discord.ext import commands

#Setting the trigger command prefit as !, I just like ! more than any other symbol for discord bots
client = commands.Bot(command_prefix = '!')
client.remove_command('help')

@client.event
async def on_ready():
    await client.change_presence(status=discord.Status.online, activity=discord.Streaming(name="The best music", url = f'https://www.youtube.com/watch?v=dQw4w9WgXcQ'))
    print('Bot is Online.')
    botOnline = True


#Is not presently working in the responses cog, so I left it here in the driver
@client.command()
async def ping(ctx):
    await ctx.send(f'Ping check, {round(client.latency * 1000)}ms')

#To avoid errors when an unset command is used
@client.event
async def on_command_error(ctx, error):
    pass


@client.command(aliases=['sd', 'SD'])
async def shutdown(ctx):
    if ctx.author.id == 308931180244238336:
        await ctx.send("Mr Stark I Don't Feel So Good")
        await ctx.bot.logout()
    else:
        await ctx.send("Lol nah fam, only Wes can shut me down like this")




# The following is for loading all Cog files.
@client.command()
async def load(ctx, extension):
    client.load_extension(f'cogs.{extension}')

#this is for unloading said files
@client.command()
async def unload(ctx, extension):
    client.unload_extension(f'cogs.{extension}')

#This is for making sure cog files are .py files
for filename in os.listdir('./dependencies'):
    if filename.endswith('.py'):
        client.load_extension(f'dependencies.{filename[:-3]}')

#This is the bot's secret token. This is redacted for safety purposes
client.run('REDACTED')
