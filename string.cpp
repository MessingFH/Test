#include <iostream>

#include "include/string.h"

// Autor(en): Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// Datum: 23.01.2022
// Kontext: LeibnizFH, C++ 6. Semester, dEA2019
// Copyright: Bjarne Messing, Daniel Mollenhauer, Jonas Schwerthelm
// 

String::String()
{
        string = "";
}

String::String(const char* data)
{
        size_t length = sizeof(data)/sizeof(char);
        string = (char*)malloc(length*sizeof(char)+1);

        for(int i = 0; i <= length; i++)
        {
                string[i] = data[i];
        }
        string[length+1] = '\0';
}     

String::~String()
{
        clear();
        string = NULL;
}

void String::append(const char* data)
{
        size_t this_length = 0;
        if(string != nullptr)
        {
                while (string[this_length] != '\0') this_length++;
        }
        
        size_t data_length = 0;
        if(data != nullptr){
                while (data[data_length] != '\0') data_length++;
        }

        string = (char*)realloc(string, this_length+data_length);

        for(int i = 0; i < data_length; i++)
        {
                string[this_length+i] = data[i];
        }
        string[this_length+data_length] = '\0';
        
}

char* String::data()
{
        if(string == nullptr)
        {
                throw std::invalid_argument("String-Memberfunction data returned Nullptr");
        }
        return string;
}

int String::find(char c)
{
        size_t this_length = 0;
        while (string[this_length] != '\0') this_length++;

        for(int i = 0; i < this_length; i++)
        {
                if(string[i] == c) 
                {
                        return i;
                }
        }
        return -1;
}

void String::print()
{
        std::cout << string << std::endl;
}

void String::clear()
{
        free(string);
        string = "";
        //string = "";
}


