#This is the Destiny 2 PVP maps Cog for Walleye bot
#This uses the first word (except for "The") in a maps names
#to present an embed that shows the maps "Callout" version and the Maps visual Version
#
#
#Last Updated: August 4th 2021
#
#Acknowledgement:
#While I made the Json file myself, the images in them are from multiple websites
#The most important of which being Warmind.io, a Destiny community source
#Live images were generally gathered from the wikia pages for Destiny 2.

import discord
import os
import json
from discord.ext import commands

class destiny2(commands.Cog):

    def __init___(self, client):
        self.client = client

    @commands.command(aliases=['D2', 'Destiny2', 'destiny2'])
    async def d2(self, ctx, *args):
        checker = 0
        toFind = "".join(args)
        toFind = toFind.capitalize() #i decided to base my Json after the pokemons json, so I followed suit here
        holder = os.getcwd()
        holder = holder + "\dependencies\destiny.json" #getting the json file location
        with open(holder, 'r') as read_file:
            map = json.load(read_file) #Loading the json into the map dictionary

        for test in map['maps']: #Finding appropriate map for user request
            if test['abbr'] == toFind:
                checker = 1
                d2embed = discord.Embed(
                    title = test['name']
                )
                d2embed.set_thumbnail(url=test['photo'])
                d2embed.set_image(url=test['callout'])

                await ctx.send(embed = d2embed)

        if checker == 0:
            await ctx.send("Perhaps the Archives are Incomplete, I couldn't find that map")


def setup(client):
    client.add_cog(destiny2(client))
