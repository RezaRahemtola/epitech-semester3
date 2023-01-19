/*
** EPITECH PROJECT, 2023
** day05
** File description:
** $DESCRIPTION
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

static void assign_c(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    free(this->str);
    this->str = s == NULL ? NULL : strdup(s);
}

static void assign_s(string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL)
        return;
    assign_c(this, str->str);
}

static void init_helper(string_t *this)
{
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
    this->split_c = &split_c;
    this->split_s = &split_s;
    this->print = &print_str;
}

void string_init(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    this->str = s == NULL ? NULL : strdup(s);
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &index_of;
    this->clear = &clear_str;
    this->length = &length_str;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy_string;
    this->c_str = &c_str;
    this->empty = &empty_string;
    this->find_c = &find_c;
    this->find_s = &find_s;
    init_helper(this);
}

void string_destroy(string_t *this)
{
    if (this == NULL)
        return;
    free(this->str);
}
