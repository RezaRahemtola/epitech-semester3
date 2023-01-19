/*
** EPITECH PROJECT, 2023
** Paradigms Seminar
** File description:
** day05
*/

#pragma once

typedef struct string_s {
    char *str;
    void (*assign_s)(struct string_s *this, const struct string_s *str);
    void (*assign_c)(struct string_s *this, const char *s);
    void (*append_s)(struct string_s *this, const struct string_s *ap);
    void (*append_c)(struct string_s *this, const char *ap);
    char (*at)(const struct string_s *this, size_t pos);
    void (*clear)(struct string_s *this);
    int (*length)(const struct string_s *this);
    int (*compare_s)(const struct string_s *this, const struct string_s *str);
    int (*compare_c)(const struct string_s *this, const char *str);
    size_t (*copy)(const struct string_s *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct string_s *this);
    int (*empty)(const struct string_s *this);
    int (*find_c)(const struct string_s *this, const char *str, size_t pos);
    int (*find_s)(const struct string_s *this, const struct string_s *str,
        size_t pos);
    void (*insert_c)(struct string_s *this, size_t pos, const char *str);
    void (*insert_s)(struct string_s *this, size_t pos,
        const struct string_s *str);
    int (*to_int)(const struct string_s *this);
    char **(*split_c)(const struct string_s *this, char separator);
    struct string_s **(*split_s)(const struct string_s *this, char separator);
    void (*print)(const struct string_s *this);
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

// Utils
void append_c(string_t *this, const char *ap);
void append_s(string_t *this, const string_t *ap);
char index_of(const string_t *this, size_t pos);
void clear_str(string_t *this);
int length_str(const string_t *this);

// Actions
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy_string(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty_string(const string_t *this);

// Manipulations
int find_c(const string_t *this, const char *str, size_t pos);
int find_s(const string_t *this, const string_t *str, size_t pos);
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);
int to_int(const string_t *this);

// Advanced
char **split_c(const string_t *this, char separator);
string_t **split_s(const string_t *this, char separator);

// End
void print_str(const string_t *this);
