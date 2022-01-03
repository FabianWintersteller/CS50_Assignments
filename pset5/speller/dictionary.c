// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];


//Index Number of words
int num_words = 0;

//Dictionary loaded
bool loaded;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int ref = hash(word);
    node *cursor = table[ref];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word_dictionary)
{
    // TODO
    int word_length = strlen(word_dictionary);
    unsigned int value = 0;

    for (int i = 0; i < word_length; i++)
    {
        value = value + 31 * tolower(word_dictionary[i]);
    }

    return value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *open_dictionary = fopen(dictionary, "r");
    if (open_dictionary == NULL)
    {
        loaded = false;
        return false;
    }
    char scan[LENGTH + 1];
    while (fscanf(open_dictionary, "%s", scan) != EOF)
    {
        node *new_connect = malloc(sizeof(node));
        if (new_connect == NULL)
        {
            loaded = false;
            return false;
        }
        strcpy(new_connect->word, scan);
        unsigned int hashed = hash(scan);

        if (table[hashed] == NULL)
        {
            table[hashed] = new_connect;
            table[hashed]->next = NULL;
        }

        else
        {
            new_connect->next = table[hashed]->next;
            table[hashed]->next = new_connect;
        }

        num_words++;
    }

    fclose(open_dictionary);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int i = num_words;
    if (loaded == false)
    {
        return 0;
    }

    else
    {
        return i;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO


    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}

