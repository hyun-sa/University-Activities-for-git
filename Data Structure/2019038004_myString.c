#include "myString.h"

#include <stdio.h>
#include <stdlib.h>

/*Convert C style string to my_string. Note that the last node always corresponds to NULL character.*/
my_string to_mystring(char* string) {
    // Implement your code
    int i = 0;
    node* previous = NULL;
    my_string start;
    start.first_symbol = NULL;
    while (string[i] != '\0')
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->character = string[i];
        temp->next = NULL;
        if (previous != NULL)
        {
            previous->next = temp;
        }
        if (start.first_symbol == NULL)
        {
            start.first_symbol = temp;
        }
        previous = temp;
        i++;
    }
    return start;
}

/*Print m_string*/
void print_mystring(my_string str) {
    // Implement your code
    node* search = str.first_symbol;
    while (search != NULL)
    {
        printf("%c", search->character);
        search = search->next;
    }
    printf("\n");
}

/*Return the length of str*/
int my_strlen(my_string str) {
    // Implement your code
    node* search = str.first_symbol;
    int size = 0;
    while (search != NULL)
    {
        size++;
        search = search->next;
    }
    return size;
}

/*Copy the source my_string to destination.
Note that this only works if the length of the destination is less than length of the source.*/
my_string my_strcpy(my_string destination, my_string source) {
    // Implement your code
    if (my_strlen(destination) < my_strlen(source))
    {
        printf("#ERROR : Destination is too small#\n");
        return destination;
    }
    else
    {
        node* temp = source.first_symbol;
        node* des = destination.first_symbol;
        destination.first_symbol = des;
        while (temp != NULL)
        {
            des->character = temp->character;
            temp = temp->next;
            if (temp == NULL)
            {
                break;
            }
            des = des->next;
        }
        des->next = NULL;
        return destination;
    }

}

// Concatenate the destination and source.
my_string my_strcat(my_string destination, my_string source) {
    // Implement your code
    node* temp = source.first_symbol;
    node* des = destination.first_symbol;
    while (des->next != NULL)
    {
        des = des->next;
    }
    while (temp != NULL)
    {
        des->next = temp;
        des = des->next;
        temp = temp->next;
    }


    return destination;
}


/* Compare str1 and str2, and return 0, 1, or -1 according to their lexicographical order.*/
int my_strcmp(my_string str1, my_string str2) {
    // Implement your code
    node* search1 = str1.first_symbol;
    node* search2 = str2.first_symbol;

    while (search1 != NULL && search2 != NULL)
    {
        if (search1->character == search2->character)
        {
            search1 = search1->next;
            search2 = search2->next;
        }
        else if (search1->character > search2->character)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    if (search1 == NULL && search2 == NULL)
    {
        return 0;
    }
    else if (search1 != NULL && search2 == NULL)
    {
        return 1;
    }
    else
    {
        return -1;
    }

}

/*Search character in str
If such character exists, return the first index and return the lengh of str otherwise.*/
int my_strchr(my_string str, int character) {
    // Implement your code
    int size = 0;
    node* search = str.first_symbol;
    while (search != NULL)
    {
        if (search->character == character)
        {
            return size;
        }
        size++;
        search = search->next;
    }
    return size;

}

/*Find the first index of str1 which contains any characters in str2
if no characters in str1, return length of str1*/
int my_strcspn(my_string str1, my_string str2) {
    // Implement your code
    int size = 0;
    node* search = str1.first_symbol;
    while (search != NULL)
    {
        node* temp = str2.first_symbol;
        while (temp != NULL)
        {
            if (search->character == temp->character)
            {
                return size;
            }
            else
            {
                temp = temp->next;
            }
        }
        size++;
        search = search->next;
    }
    return size;

}

/*Check if str1 contains str2.
If str1 contains str2, return the first occurence of str2 in str1
if not contains, return -1*/
int my_strstr(my_string str1, my_string str2) {
    // Implement your code
    int size = 0;
    node* search = str1.first_symbol;
    int chk = 1;
    while (search != NULL)
    {
        chk = 1;
        node* temp = str2.first_symbol;
        node* search_temp = search;
        while (temp != NULL)
        {
            if (search_temp->character == temp->character)
            {
                temp = temp->next;
                search_temp = search_temp->next;
            }
            else
            {
                chk = 0;
                break;
            }
        }
        if (chk != 1)
        {
            size++;
            search = search->next;
        }
        else
        {
            return size;
        }

    }
    return -1;
}

/*Reverse my_string*/
my_string my_strrev(my_string str) {
    // Implement your code
    node* previous = NULL;
    my_string start;
    start.first_symbol = NULL;
    int size = my_strlen(str);
    for (int i = 0; i < size; i++)
    {
        int j = i + 1;
        node* search = str.first_symbol;
        while (j < size)
        {
            search = search->next;
            j++;
        }
        node* temp = (node*)malloc(sizeof(node));
        temp->character = search->character;
        temp->next = NULL;
        if (previous != NULL)
        {
            previous->next = temp;
        }
        if (start.first_symbol == NULL)
        {
            start.first_symbol = temp;
        }
        previous = temp;
    }
    return start;
}
