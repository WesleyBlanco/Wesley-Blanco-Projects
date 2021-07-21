import discord
import os
import json
from discord.ext import commands

client = commands.Bot(command_prefix = '!')
client.remove_command('help')

@client.event
async def on_ready():
    await client.change_presence(status=discord.Status.online, activity=discord.Streaming(name="The best music", url = f'https://www.youtube.com/watch?v=dQw4w9WgXcQ'))
    print('Bot is Online.')

#Is not presently working in the responses cog, so I left it here in the driver
@client.command()
async def ping(ctx):
    await ctx.send(f'Ping check, {round(client.latency * 1000)}ms')

#To avoid errors when an unset command is used
#@client.event
#async def on_command_error(ctx, error):
#    pass


# The following is for loading all dependencies files.
@client.command()
async def load(ctx, extension):
    client.load_extension(f'cogs.{extension}')

#this is for unloading said files
@client.command()
async def unload(ctx, extension):
    client.unload_extension(f'cogs.{extension}')

#This is for making sure dependency files are .py files
for filename in os.listdir('./dependencies'):
    if filename.endswith('.py'):
        client.load_extension(f'dependencies.{filename[:-3]}')

#This is the bot's secret token. This is redacted for safety purposes
client.run('REDACTED')
