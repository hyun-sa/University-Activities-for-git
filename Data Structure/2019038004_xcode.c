#include "xcode.h"
#include "stack.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************Pre-defined functions : TO NOT TOUCH ******************************************/

/*Print error message*/
void print_error() {
	printf("ERROR\n");
	return;
}


/***********************************************************************************************************/


/*Read the given 'file' and return the corresponding Xtree.*/
xnode* construct_xtree(char* file) {
//Implement your function in here
    FILE* fp = fopen(file, "r");
    xnode* root = NULL;
    xnode* temp = NULL;
    char buffer[4096] = { 0 };
    heap* heap_p = (heap*)malloc(sizeof(heap));
    create(heap_p);
    double cnt = 0;
    int temp_i = 0;
    double d0 = 0;
    double d1 = 0;
    double rem_p = 0;
    while ((temp_i = fread(buffer, sizeof(char), 4096, fp)) > 0)
    {
        for (int i=0; i<temp_i; i++)
        {
            if (buffer[i] == '0')
            {
                d0 += 1;
            }
            else if (buffer[i] == '1')
            {
                d1 += 1;
            }
            else
            {
                print_error();
                return NULL;
            }
        }
        memset(buffer, 0, 4096);
    }
    cnt = d0 + d1;
    int cnt_2 = 2;
    d0 /= cnt;
    d1 /= cnt;

    root = (xnode*)malloc(sizeof(xnode));
    root->leftchild = (xnode*)malloc(sizeof(xnode));
    root->leftchild->p = d0;
    root->leftchild->string = (char*)malloc(strlen("0")+1);
    strcpy(root->leftchild->string, "0");
    root->rightchild = (xnode*)malloc(sizeof(xnode));
    root->rightchild->p = d1;
    root->rightchild->string = (char*)malloc(strlen("1")+1);
    strcpy(root->rightchild->string, "1");

    temp = root;
    insert(heap_p, temp->rightchild);
    insert(heap_p, temp->leftchild);


    while (cnt_2 < code_size)
    {
        temp = deletemin(heap_p);
        cnt_2++;
        temp->leftchild = (xnode*)malloc(sizeof(xnode));
        temp->leftchild->p = temp->p * d0;
        temp->leftchild->string = (char*)malloc(strlen(temp->string)+2);
        strcpy(temp->leftchild->string, temp->string);
        strcat(temp->leftchild->string, "0");
        temp->rightchild = (xnode*)malloc(sizeof(xnode));
        temp->rightchild->p = temp->p * d1;
        temp->rightchild->string = (char*)malloc(strlen(temp->string) + 2);
        strcpy(temp->rightchild->string, temp->string);
        strcat(temp->rightchild->string, "1");
        insert(heap_p, temp->leftchild);
        insert(heap_p, temp->rightchild);
    }
    fclose(fp);
    return root;
}

/*
 Construct a codebook array w.r.t. a given Xtree (xtree is the root node of Xtree).
  After that, Create a "codebook.txt" file based on that array
 */
void codebook(xnode* xtree) {
//Implement your function in here
    FILE* fp = fopen("codebook.txt", "w");
    xnode* temp = xtree;
    heap* heap_p = (heap*)malloc(sizeof(heap));
    create(heap_p);
    char** rec = NULL;
    int i = 2;
    rec = (char**)malloc(sizeof(char*) * code_size);
    insert(heap_p, temp->leftchild);
    insert(heap_p, temp->rightchild);
    while (i < code_size)
    {
        temp = deletemin(heap_p);
        insert(heap_p, temp->leftchild);
        insert(heap_p, temp->rightchild);
        i++;
    }

    i=0;
    while (i < code_size)
    {
        temp = deletemin(heap_p);
        rec[i] = (char*)malloc(strlen(temp->string)+1);
        strcpy(rec[i], temp->string);
        i += 1;
    }
    for (int k=0; k<code_size; k++)
    {
        for (int h=k; h<code_size; h++)
        {
            if (strcmp(rec[h], rec[k]) > 0)
            {
                char* temp_code = NULL;
                temp_code = rec[h];
                rec[h] = rec[k];
                rec[k] = temp_code;
            }
        }
    }
    i = code_size -1;
    for (int j = 0; j < code_size; j++)
    {
        char* temp_c = (char*)malloc(strlen(rec[i]) + 1);
        strcpy(temp_c, rec[i]);
        code_book[j] = temp_c;

        int num = j;
        char* rec_num = (char*)malloc(b+1+strlen(code_book[j])+2);
        strcpy(rec_num, "");

        for (int k = 0; k < b; k++)
        {
            if (num % 2 == 0)
            {
                strcat(rec_num, "0");
            }
            else
            {
                strcat(rec_num, "1");
            }
            num /= 2;
        }
        strrev(rec_num);
        strcat(rec_num, " ");
        strcat(rec_num, code_book[j]);
        strcat(rec_num, "\n");
        fputs(rec_num, fp);
        i -= 1;
    }

    fclose(fp);
}

/*
 * Compress the 'file' using given Xtree and current code_book, and store it into "output.txt".
 */
void compress_x(xnode* xtree, char* file) {
//Implement your function in here
    FILE* fp_r = fopen(file, "r");
    FILE* fp_w = fopen("output.txt", "w");
    double cnt_r = 0;
    double cnt_w = 0;
    char temp_c = 0;
    char* temp = NULL;
    temp = (char*)malloc(code_size+1);
    strcpy(temp, "");
    while ((temp_c = fgetc(fp_r)) != EOF)
    {
        cnt_r += 1;
        char temp_char[2] = { temp_c, '\0' };
        strcat(temp, temp_char);
        for (int i = 0; i < code_size; i++)
        {
            if (!strcmp(temp, code_book[i]))
            {
                char* rec_num = (char*)malloc(b+1);
                strcpy(rec_num, "");
                int num = i;
                for (int k = 0; k < b; k++)
                {
                    if (num % 2 == 0)
                    {
                        strcat(rec_num, "0");
                    }
                    else
                    {
                        strcat(rec_num, "1");
                    }
                    num /= 2;
                }
                cnt_w += b;
                strrev(rec_num);
                fputs(rec_num, fp_w);
                strcpy(temp, "");
                break;
            }
        }
    }
    fputs("\n", fp_w);
    cnt_w += strlen(temp);
    fputs(temp, fp_w);
    fclose(fp_r);
    fclose(fp_w);
    printf("Compression ratio : %.3lf\n", cnt_w / cnt_r);
}

/*
 From 'codebook' (codebook file) and 'output' (compressed file), Decompress the original string and store it as "input_original.txt"
 The generated file (input_original.txt) and the original file should be identical.
 */
void decompress_x(char* output, char* codebook) {
//Implement your function in here
    FILE* fp_output = fopen(output, "r");
    FILE* fp_codebook = fopen(codebook, "r");
    FILE* fp = fopen("input_original.txt", "w");
    char temp_c = 0;
    char** book = NULL;
    char** code = NULL;
    char buffer[1024];
    char* str;
    book = (char**)malloc(sizeof(char*) * code_size);
    code = (char**)malloc(sizeof(char*) * code_size);
    char* token;
    int i = 0;

    while (i < code_size)
    {
        str = fgets(buffer, 1024, fp_codebook);
        token = strtok(str, " ");
        book[i] = (char*)malloc(strlen(token)+1);
        strcpy(book[i], token);
        token = strtok(NULL, " ");
        code[i] = (char*)malloc(strlen(token)+1);
        strcpy(code[i], token);
        i += 1;
    }

    char* temp = NULL;
    temp = (char*)malloc(b + 1);
    strcpy(temp, "");
    i = 0;
    temp_c = fgetc(fp_output);
    while (temp_c != '\n')
    {
        char temp_char[2] = { temp_c, '\0' };
        strcat(temp, temp_char);
        i += 1;
        if (i % b == 0)
        {
            for (int j = 0; j < code_size; j++)
            {
                if (!strcmp(temp, book[j]))
                {
                    int temp_len = strlen(code[j]);
                    for (int k=0; k < temp_len-1; k++)
                    {
                        fputc(code[j][k], fp);
                    }
                    strcpy(temp, "");
                }
            }
            if (strlen(temp) != 0)
            {
                print_error();
                return;
            }
        }
        temp_c = fgetc(fp_output);
    }
    while ((temp_c = fgetc(fp_output)) != EOF)
    {
        fputc(temp_c, fp);
    }
}
