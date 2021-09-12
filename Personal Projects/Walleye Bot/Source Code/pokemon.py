#This is the COG for Walleye Bot for Pokemon functionality
#This Cog will return an embed with pokemon stats given a pokemon name
#This does not include Generation 8, Sword and Shield, data
#
#Last Updated: August 4th 2021
#
#Acknowledgement:
#This file works with the json file pokemons.json, which was recieved from the github registry https://github.com/joseluisq/pokemons

import discord
import json
import os
from discord.ext import commands


class Pokemon(commands.Cog):

    def __init___(self, client):
        self.client = client


    @commands.command(aliases=['pokemon', 'poke'])
    async def Pokemon(self, ctx, *args):
        MegaChecker = 0 #This is for Mega Evolution Pokemon. The json file groups them in as normal pokemon, So i had to use a checker to figure out which one should be indicated as Mega
        MegaFixer = ""
        toFind = "".join(args)
        toFind = toFind.capitalize() #Names in the file are stored capitalized as a first letter so this fixes this
        holder = os.getcwd() #Getting the first part of the path needed
        holder = holder + "\dependencies\pokemons.json" #This is the path I have on my computer to get to the Json file
        with open(holder, 'r') as read_file:
            pokedex = json.load(read_file) #Loading the json file into pokedex

        for pokemon in pokedex['results']: #Searching for the pokemon given by user
            if pokemon['name'] == toFind:
                types = ", ".join(pokemon['type'])

                #Most Megas in this JSON file appear after the normal entry
                #The exception to this is Charizard and Mewtwo, who have two Megas. Their Megas, X and Y, appear before their normal entry
                #This logic Block fixes their names to be correct
                #And also adds the word Mega before any Mega entries that are published
                if (pokemon['name'] == 'Charizard' or pokemon['name'] == 'Mewtwo') and MegaChecker == 0:
                    MegaFixer = "X "
                elif MegaChecker == 1:
                    MegaFixer = "Mega "
                    if pokemon['name'] == 'Charizard' or pokemon['name'] == "Mewtwo":
                        MegaFixer = "Y "
                else:
                    MegaFixer = ""

                #This confirms that the first entry has been passed and that the second entry would be a Mega
                MegaChecker = MegaChecker + 1

                #This is the embed for posting stats
                pokemonEmbed = discord.Embed(
                    title = MegaFixer + pokemon['name'] + " # " + pokemon['national_number'],
                    description = types
                )
                pokemonEmbed.set_thumbnail(url=pokemon['sprites']['animated'])
                pokemonEmbed.add_field(name="Total Base Stats", value = pokemon['total'], inline=False)
                pokemonEmbed.add_field(name = "HP", value = pokemon['hp'])
                pokemonEmbed.add_field(name="Attack", value= pokemon['attack'])
                pokemonEmbed.add_field(name="Special Attack", value= pokemon['sp_atk'])
                pokemonEmbed.add_field(name="Defense", value = pokemon['defense'])
                pokemonEmbed.add_field(name="Special Defense", value=pokemon['sp_def'])
                pokemonEmbed.add_field(name="Speed", value=pokemon['speed'])

                await ctx.send(embed=pokemonEmbed)


        if MegaChecker == 0:
            await ctx.send("I couldn't find that one, maybe try !Digimon? Or learn to spell")


def setup(client):
    client.add_cog(Pokemon(client))
