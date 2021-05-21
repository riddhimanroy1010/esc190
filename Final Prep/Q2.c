//
// Created by riddh on 4/20/2021.
//

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct table_elem{
    int key;
    char* value;
    bool full;
    bool deleted;
};

struct hashtable{
    size_t table_size;
    size_t n_elems;
    struct table_elem *table;
    int (*probe_fn)(int i, int key);
    int (*hash_fn)(int key, int table_size);
    double max_load;
};

void ht_create(struct hashtable **ht, double max_load, int (*hash_fn)(int key, int table_size), int (*probe_fn)(int i, int value))
{
    *ht = (struct hashtable *)malloc(sizeof(struct hashtable));
    (*ht)->table = (struct table_elem *)calloc(sizeof(struct table_elem) * 10, 1);
    (*ht)->table_size = 10;
    (*ht)->n_elems = 0;
    (*ht)->probe_fn = probe_fn;
    (*ht)->hash_fn = hash_fn;
    (*ht)->max_load = max_load;

}
void ht_destroy(struct hashtable *ht)
{
    free(ht->table);
    free(ht);
}


//d[k] = v
//ht[key] = value

//Return true on success, false on failure
bool ht_set(struct hashtable *ht, int key, char* value)
{
    int hash = (ht->hash_fn)(key, ht->table_size);
    int add = 0; //f(key, i)
    int i = 0;
    //while we haven't found an empty slot for key,
    // keep trying at index hash + add, where add is f(key, i)
    while (ht->table[(hash+add)%ht->table_size].key != key && ht->table[(hash+add)%ht->table_size].full  && i < ht->table_size){
        i += 1;
        add = ht->probe_fn(i, key);
    }

    if(i == ht->table_size){
        return false;
    }

    if(!(ht->table[(hash+add)%ht->table_size].full && ht->table[(hash+add)%ht->table_size].key == key)){
        ht->n_elems += 1;
    }
    ht->table[(hash+add)%ht->table_size].key = key;
    ht->table[(hash+add)%ht->table_size].value = value;
    ht->table[(hash+add)%ht->table_size].full = true;
    ht->table[(hash+add)%ht->table_size].deleted = false;


    if( ((double)(ht->n_elems + 1))/ht->table_size >= ht->max_load ){
        struct hashtable *ht1;
        ht_create(&ht1, ht->max_load, ht->hash_fn, ht->probe_fn);
        ht1->table = realloc(ht1->table, sizeof(struct table_elem) * ht->table_size * 2);
        ht1->table_size = ht->table_size * 2;
        memset(ht1->table, 0, sizeof(struct table_elem) * ht1->table_size);
        for(int j = 0; j < ht->table_size; j++){
            if(ht->table[j].full && !ht->table[j].deleted){
                ht_set(ht1, ht->table[j].key, ht->table[j].value);
            }
        }

        free(ht->table);
        ht->table = ht1->table;
        ht->table_size = ht1->table_size;
        free(ht1);
    }

    return true;
}

bool ht_delete(struct hashtable *ht, int key)
{
    int hash = (ht->hash_fn)(key, ht->table_size);
    int add = 0; //f(key, i)
    int i = 0;
    while(ht->table[(hash+add)%ht->table_size].key != key && i < ht->table_size){
        i += 1;
        add = ht->probe_fn(i, key);
    }
    if(ht->table[(hash+add)%ht->table_size].key == key){
        ht->table[(hash+add)%ht->table_size].deleted = true;
        return true;
    }else{
        return false;
    }

}

bool ht_in(struct hashtable *ht, int key)
{
    int hash = (ht->hash_fn)(key, ht->table_size);
    int add = 0;
    int i = 0;
    while(ht->table[(hash+add)%ht->table_size].key != key && ht->table[(hash+add)%ht->table_size].full && i < ht->table_size){
        i += 1;
        add = ht->probe_fn(i, key);
    }

    return ht->table[(hash+add)%ht->table_size].key == key && !ht->table[(hash+add)%ht->table_size].deleted;
}

char* ht_get(struct hashtable *ht, int key)
{

    int hash = (ht->hash_fn)(key, ht->table_size);
    int add = 0;
    int i = 0;
    while(ht->table[(hash+add)%ht->table_size].key != key && ht->table[(hash+add)%ht->table_size].full && i < ht->table_size){
        i += 1;
        add = ht->probe_fn(i, key);
    }

    return ht->table[(hash+add)%ht->table_size].value;
}

int hash_fn(int key, int table_size){
    return key % table_size;
}

int probe_fun(int i, int key){
    return i;
}

int key_maker(char* str)
{
    return atoi(str)%26;
}

int repeats(char **strs, int strs_sz)
{
    struct hashtable *ht;
    int keys[strs_sz];
    ht_create(&ht, 0.8, hash_fn, probe_fun);
    for (int i = 0; i < strs_sz; i++)
    {
        int key = key_maker(*strs + i);
        for (int j = 0; j < i; j++)
        {
            if (key == keys[j])
            {
                return 1;
            }
        }
        keys[i] = key;
        ht_set(ht, key, strs[i]);

    }
    return 0;
}
//Function runs in O(n) time since it checks for repeats within the hashing while hashing.
// It only goes through the full O(n).  Hashing based off letters will lead to the same key hence repeats/



