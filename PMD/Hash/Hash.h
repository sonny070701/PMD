typedef enum{FALSE,TRUE} BOOL;
typedef void* TYPE;

struct STRNODE {
	TYPE data;
	struct STRNODE* next;
};

typedef struct STRNODE* NODE;

struct STRLIST {
	NODE first,last;
	int size;
};

struct KEYVALSTR {
	char key[50];
	char value[50];
};

typedef struct STRLIST* LIST;
typedef struct KEYVALSTR* KEYVAL; 

long long myhash(TYPE data);
LIST list_create();
void list_insert(LIST list,TYPE data);
KEYVAL keyval_create(char *key,char *value);
void list_print(LIST list);
void keyval_print(KEYVAL kv);
KEYVAL keyval_search(LIST list,char *key);