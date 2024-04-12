// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int count = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
// Hash the word to get the index in the hash table
    unsigned int index = hash(word);

    // Traverse the linked list at the index to find the word
    node *cursor = table[index];
    while (cursor != NULL)
    {
        // Compare the word in the current node with the target word
        if (strcasecmp(cursor->word, word) == 0)
        {
            // Word found, return true
            return true;
        }
        // Move to the next node
        cursor = cursor->next;
    }

    // Word not found in the dictionary
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
         {
            // Handle file opening error
            return 1;
         }
    // Read each word in the file
    char word[LENGTH + 1];

    while (fscanf(source, "%s", word) != EOF)
    {
        //node *head = NULL;
        node *new_node = malloc(sizeof(node));
         // Assign the value of 'word' to the next 'word' member of the new node
        if (new_node == NULL)
        {
            // Handle memory allocation error
            fclose(source);
            return false;
        }
        strcpy(new_node->word, word);
        // insert words into table
        //new_node->next;

        unsigned int index = hash(word); //calling the hash function to give return toupper(word[0]) - 'A'; ASCII value from start

        // Insert the new node at the beginning of the list
        new_node->next = table[index]; //removing 'head'
        table[index] = new_node; //replacing 'head' by 'table[N]'
        count ++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

     // Check if any bucket in the table has a non-empty linked list
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            // Dictionary is loaded, return the count
            return count;
        }
    }

    // If none of the buckets have a non-empty linked list, return 0
    return 0;

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{


    for (int i = 0; i < N; i++)
    {
    node *cursor = table[i];
    while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        table[i] = NULL;
    }
    return true;
}
