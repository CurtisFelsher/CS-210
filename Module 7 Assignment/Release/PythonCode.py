#Curtis Felsher
#CS-210
#April 13th, 2022

import re
import string




#defines the CountAllItems function
def CountAllItems():
    #Opens the text file to read
    text = open("CS210_Project_Three_Input_File.txt", "r")

    #creates a dictionary to store the words
    dictionary = dict()

    #Scans each line of file
    for line in text:
        #Strips spaces then makes the words lowercase to identify easier
        line = line.strip()
        item = line.lower()
        
        #Checks dicitonary to see if item is there and adds it
        if item in dictionary:
            dictionary[item] = dictionary[item] + 1
        else:
            dictionary[item] = 1

    #Outputs dictionary contents
    for key in list (dictionary.keys()):
        print(key.capitalize(), "-", dictionary[key])

    #Closes the file
    text.close()






#Defines the CountSpecific function
def CountSpecific(userInput):

    #Makes input lower case to make words easier to identify
    userInput = userInput.lower()

    #Opens the text file to read
    text = open("CS210_Project_Three_Input_File.txt", "r")

    #itemCount variable to hold search term count
    itemCount = 0

    #Scans each line of file
    for line in text:
        #Strips spaces then makes the words lowercase to identify easier 
        line = line.strip()
        item = line.lower()
        
        #Checks if the line item is the also the users search term
        if item == userInput:
            itemCount += 1

    #Returns amount of frequency of search term
    return itemCount

    #Closes the file
    text.close()







#Defines CollectItemData function
def CollectItemData():
    #Opens the text file to read
    text = open("CS210_Project_Three_Input_File.txt", "r")

    #Creates the frequency.dat file to write to
    frequency = open("frequency.dat", "w")

    #Generates a dictionary to store the words
    dictionary = dict()

    #Scans each line of file
    for line in text:
        ##Strips spaces then makes the words lowercase to identify easier 
        line = line.strip()
        word = line.lower()
        
        #Checks dicitonary to see if word is there and adds it
        if word in dictionary:
            dictionary[word] = dictionary[word] + 1
        else:
            dictionary[word] = 1

    #Stores each word and frequency in frequency.dat
    for key in list (dictionary.keys()):
        #Formats the output
        frequency.write(str(key.capitalize()) + " " + str(dictionary[key]) + "\n")

    #Closes the files
    text.close()
    frequency.close()