#include <cstdio>
#include <cstdlib>
#include <cassert>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define UTEST(cond, flag) {\
    if(!(cond)) {\
        flag = false;\
        printf(ANSI_COLOR_RED "Unit testing failed: %s\n" ANSI_COLOR_RESET, #cond); \
    }\
}

enum listValidity {
    OK = 0,
    LIST_NOT_FOUND = 1,
    CORRUPTED = 2
};

struct list_t {
    void **value;
    long long *next;
    long long *prev;
    long long head;
    long long tail;
    size_t size;
    size_t maxsize;
    long long emptyHead;
    // stack_t free;
};

list_t *createList(size_t maxsize);

long long getElementByPosition(list_t *list, size_t position);

long long getFirstElement(list_t *list);

long long getLastElement(list_t *list);

long long getNextElement(long long node);

long long getPreviousElement(long long node);

long long findFirstNode(list_t *list, void *value, bool (*cmp)(void *, void *));

long long findLastNode(list_t *list, void *value, bool (*cmp)(void *, void *));

long long getEmpty(list_t *list);

void addEmpty(list_t *list, long long num);

listValidity validateList(list_t *list);

void deleteList(list_t **list);

int addToHead(list_t *list, void *value);

int addToTail(list_t *list, void *value);

int insertAfter(list_t *list, long long elem, void *value);

int insertBefore(list_t *list, long long elem, void *value);

void deleteNode(list_t *list, long long elem);

void clearList(list_t *list);

void sortList(list_t *list);

void dumpList(list_t *list, const char *dumpFilename, char *(*nodeDump)(list_t *, long long) = nullptr);

char *nodeDump(list_t *list, long long node) { // Example function
    static char str[65] = "";
    sprintf(str, "{VALUE|%d}|{NEXT|%lld}|{PREVIOUS|%lld}", *(int *) (list->value[node]), list->next[node],
            list->prev[node]);
    return (char *) str;
}

/**
 * Function that performs unit testing
 * @return Lib validity
 */

bool doUnitTesting() {
    bool valid = true;
    list_t *testList = createList(10);
    UTEST(testList->head == -1, valid);
    UTEST(testList->tail == -1, valid);
    int vals[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    addToHead(testList, &vals[1]);
    UTEST(testList->head == 0, valid);
    UTEST(testList->tail == 0, valid);
    UTEST(testList->size == 1, valid);

    addToTail(testList, &vals[8]);
    UTEST(testList->tail == 1, valid);
    UTEST(testList->head == 0, valid);
    UTEST(testList->size == 2, valid);

    insertAfter(testList, 1, &vals[9]);
    UTEST(testList->size == 3, valid);
    UTEST(testList->tail == 2, valid);
    UTEST(testList->head == 0, valid);

    insertBefore(testList, 0, &vals[0]);
    UTEST(testList->size == 4, valid);
    UTEST(testList->tail == 2, valid);
    UTEST(testList->head == 3, valid);

    UTEST(getElementByPosition(testList, 0) == 3, valid);
    UTEST(getElementByPosition(testList, 1) == 0, valid);
    UTEST(getElementByPosition(testList, 2) == 1, valid);
    UTEST(getElementByPosition(testList, 3) == 2, valid);

    for (int i = 2; i < 8; i++) {
        insertAfter(testList, getElementByPosition(testList, i - 1), &vals[i]);
        UTEST(testList->value[getElementByPosition(testList, i)] == &vals[i], valid);
    }

    UTEST(testList->size == 10, valid);
    UTEST(!addToHead(testList, nullptr), valid);
    UTEST(!addToTail(testList, nullptr), valid);
    UTEST(!insertAfter(testList, 0, nullptr), valid);
    UTEST(!insertBefore(testList, 0, nullptr), valid);

    deleteNode(testList, 3);
    UTEST(testList->size == 9, valid);
    UTEST(testList->head == 0, valid);

    deleteNode(testList, 2);
    UTEST(testList->size == 8, valid);
    UTEST(testList->tail == 1, valid);

    UTEST(validateList(testList) == OK, valid);
    sortList(testList);
    dumpList(testList, "unitTestingDump.dot", nodeDump);
    deleteList(&testList);
    UTEST(!testList, valid);
    return valid;
}


int main() {
    if (doUnitTesting())
        printf(ANSI_COLOR_GREEN "##############################\nUnit testing finished successfully!\n##############################" ANSI_COLOR_RESET);
    else
        printf(ANSI_COLOR_RED "##############################\nUnit testing failed!\n##############################" ANSI_COLOR_RESET);
}

/**
 * List "constructor" i. e. function that creates and initializes list_t
 * @param maxsize Maximal size of list
 * @return Pointer to list_t
 */

list_t *createList(size_t maxsize) {
    list_t *list = (list_t *) calloc(1, sizeof(list_t));
    list->size = 0;
    list->value = (void **) calloc(maxsize, sizeof(void *));
    list->maxsize = maxsize;
    list->next = (long long *) calloc(maxsize, sizeof(long long));
    list->prev = (long long *) calloc(maxsize, sizeof(long long));
    list->head = -1;
    list->tail = -1;
    list->emptyHead = 0;
    //list->free = {};
    //stackConstruct(&list->free, "ListFreeStack", maxsize, -1);

    for (long long i = maxsize - 1; i >= 0; i--) {
        list->next[i] = -1;
        list->prev[i] = -1;
        list->value[i] = (void *) (i + 1);
        //stackPush(&list->free, i);
    }
    list->value[maxsize - 1] = nullptr;
    return list;
}

/**
 * Function that clears list
 * @param list Pointer to list_t
 */

void clearList(list_t *list) {
    assert(list);

    long long curNode = list->head;
    long long next = -1;

    while (curNode != list->tail) {
        next = list->next[curNode];

        list->next[curNode] = -1;
        list->prev[curNode] = -1;
        list->value[curNode] = (void *) list->emptyHead;
        list->emptyHead = curNode;
        // stackPush(&list->free, curNode);

        curNode = next;
    }

    list->head = -1;
    list->tail = -1;
    list->size = 0;
}

/**
 * List "destructor" i. e. function that deletes list
 * @param list Pointer to pointer to list
 */

void deleteList(list_t **list) {
    assert(list);
    assert(*list);

    clearList(*list);

    //stackDestruct(&(*list)->free);

    free(*list);
    *list = nullptr;
}

/**
 * Function that adds elements to list's head
 * @param list Pointer to list_t
 * @param value Void pointer to value
 * @return 0 if error occures, 1 otherwise
 */

int addToHead(list_t *list, void *value) {
    assert(list);

    if (list->size == list->maxsize)
        return 0;

    long long temp = list->head;
    long long newNode = getEmpty(list);

    // stackPop(&list->free, &newNode);

    list->value[newNode] = value;

    if (temp != -1) {
        list->prev[temp] = newNode;
    }

    list->head = newNode;

    if (list->tail == -1) {
        list->tail = newNode;
    }

    list->size++;

    return 1;
}

/**
 * Function that returns position of an empty element
 * @param list Pointer to list
 * @return Physical number of empty cell
 */

long long getEmpty(list_t *list) {
    assert(list);

    long long empty = list->emptyHead;
    list->emptyHead = (long long) list->value[list->emptyHead];
    return empty;
}

/**
 * Function that adds cell to the list of the empty cells
 * @param list Pointer to list_t
 * @param num Physical number of cell
 */

void addEmpty(list_t *list, long long num) {
    assert(list);

    list->value[num] = (void *) list->emptyHead;
    list->emptyHead = num;
}

/**
 * Function that adds value to the tail of the list
 * @param list Pointer to list_t
 * @param value Void pointer to value
 * @return 0 if error occures, 1 otherwise
 */

int addToTail(list_t *list, void *value) {
    assert(list);

    if (list->size == list->maxsize)
        return 0;

    long long temp = list->head;
    long long newNode = getEmpty(list);

    list->value[newNode] = value;

    if (temp != -1) {
        list->next[temp] = newNode;
    }

    list->tail = newNode;

    if (list->head == -1) {
        list->head = newNode;
    }

    list->size++;

    return 1;
}

/**
 * Function that inserts element after the given one
 * @param list Pointer to list_t
 * @param elem Physical number of element
 * @param value Void pointer to value
 * @return 0 if error occures, 1 otherwise
 */

int insertAfter(list_t *list, long long elem, void *value) {
    assert(list);
    assert(elem >= 0);

    if (list->size == list->maxsize)
        return 0;

    long long tmp = list->next[elem];
    long long newNode = getEmpty(list);

    list->prev[newNode] = elem;
    list->next[newNode] = tmp;
    list->value[newNode] = value;

    list->next[elem] = newNode;

    if (tmp != -1) {
        list->prev[tmp] = newNode;
    } else {
        list->tail = newNode;
    }

    list->size++;

    return 1;
}

/**
 * Function that inserts element before the given one
 * @param list Pointer to list_t
 * @param elem Physical number of element
 * @param value Void pointer to value
 * @return 0 if error occures, 1 otherwise
 */

int insertBefore(list_t *list, long long elem, void *value) {
    assert(list);
    assert(elem >= 0);

    if (list->size == list->maxsize)
        return 0;

    long long tmp = list->prev[elem];
    long long newNode = getEmpty(list);

    list->next[newNode] = elem;
    list->prev[newNode] = tmp;
    list->value[newNode] = value;

    list->prev[elem] = newNode;

    if (tmp != -1) {
        list->next[tmp] = newNode;
    } else {
        list->head = newNode;
    }

    list->size++;

    return 1;
}

/**
 * Function that gets the first element of the list
 * @param list Poiter to list_t
 * @return Physical number of element
 */

long long getFirstElement(list_t *list) {
    assert(list);

    return list->head;
}

/**
 * Function that gets the last element of the list
 * @param list Poiter to list_t
 * @return Physical number of element
 */

long long getLastElement(list_t *list) {
    assert(list);

    return list->tail;
}

/**
 * Function that gets element after the given one
 * @param list Poiter to list_t
 * @param node Physical adress of element
 * @return Physical number of element
 */

long long getNextElement(list_t *list, long long node) {
    assert(list);
    assert(node >= 0);

    return list->next[node];
}

/**
 * Function that gets element before the given one
 * @param list Pointer to list_t
 * @param node Physical address of element
 * @return Physical number of element
 */

long long getPreviousElement(list_t *list, long long node) {
    assert(list);
    assert(node >= 0);

    return list->prev[node];
}

/**
 * Function that returns physical address by logical adress
 * @param list Pointer to list_t
 * @param position Logical position
 * @return Physical position
 */

long long getElementByPosition(list_t *list, size_t position) {
    assert(list);

    if (position >= list->size)
        return -1;

    long long curNode = list->head;

    for (size_t i = 0; i < position; i++) {
        if (curNode == -1)
            return curNode;
        curNode = list->next[curNode];
    }

    return curNode;
}

/**
 * Function that finds first occurance of the value
 * @param list Pointer to list_t
 * @param value Void to pointer value
 * @param cmp Pointer to comparator
 * @return Physical address of the element
 */

long long findFirstNode(list_t *list, void *value, bool (*cmp)(void *, void *)) {
    assert(list);

    long long node = list->head;

    for (size_t i = 0; i < list->size; i++) {
        if (node == -1)
            return -1;

        if (cmp(list->value[node], value))
            return node;

        node = list->next[node];
    }

    return -1;
}

/**
 * Function that finds last occurance of the value
 * @param list Pointer to list_t
 * @param value Void to pointer value
 * @param cmp Pointer to comparator
 * @return Physical address of the element
 */

long long findLastNode(list_t *list, void *value, bool (*cmp)(void *, void *)) {
    assert(list);

    long long node = list->tail;

    for (size_t i = list->size - 1; i >= 0; i--) {
        if (node == -1)
            return -1;

        if (cmp(list->value[node], value))
            return node;

        node = list->prev[node];
    }

    return -1;
}

/**
 * Function that deletes node
 * @param list Pointer to list_t
 * @param node Physical adress of the node
 */

void deleteNode(list_t *list, long long node) {
    assert(list);
    assert(node >= 0);
    assert(node < list->size);

    if (list->prev[node] != -1)
        list->next[list->prev[node]] = list->next[node];
    else
        list->head = list->next[node];

    if (list->next[node] != -1)
        list->prev[list->next[node]] = list->prev[node];
    else
        list->tail = list->prev[node];

    list->size--;
    // stackPush(&list->free, node);
    addEmpty(list, node);
}

/**
 * Function that validates the list
 * @param list Pointer to list_t
 * @return List Validity value
 */

listValidity validateList(list_t *list) {
    if (!list)
        return LIST_NOT_FOUND;

    size_t size = list->size;
    long long node = list->head;

    for (size_t i = 0; i < size - 1; i++) {
        if (node == -1)
            return CORRUPTED;

        node = list->next[node];
    }

    if (list->tail != node)
        return CORRUPTED;

    return OK;
}

/**
 * Function that dumps list
 * @param list Pointer to list
 * @param dumpFilename Dump filename
 * @param nodeDump Optional function that renders value
 */

void dumpList(list_t *list, const char *dumpFilename, char *(*nodeDump)(list_t *, long long)) {
    assert(list);
    assert(dumpFilename);

    FILE *dumpFile = fopen(dumpFilename, "w");
    fprintf(dumpFile, "digraph {\n");

    long long node = list->head;

    fprintf(dumpFile, "node%lld[label=\"{{%lld}", node, node);
    if (nodeDump) {
        fprintf(dumpFile, "|{%s}", (*nodeDump)(list, node));
    }
    fprintf(dumpFile, "}\",shape=record];\n");

    while (node != list->tail) {
        fprintf(dumpFile, "node%lld[label=\"{{%lld}", list->next[node], list->next[node]);
        if (nodeDump) {
            fprintf(dumpFile, "|{%s}", (*nodeDump)(list, list->next[node]));
        }
        fprintf(dumpFile, "}\",shape=record];\n");

        fprintf(dumpFile, "node%lld -> node%lld;\n", node, list->next[node]);
        fprintf(dumpFile, "node%lld -> node%lld;\n", list->next[node], node);
        node = list->next[node];
    }

    fprintf(dumpFile, "Head -> node%lld;\n", list->head);
    fprintf(dumpFile, "node%lld -> Tail;\n", list->tail);
    fprintf(dumpFile, "}");
    fclose(dumpFile);
}

void sortList(list_t *list) {
    assert(list);
    long long node = list->head;
    void *swapValue = nullptr;
    long long swapPos = 0;
    long long nextNode = 0;
    long long pos = 0;

    while (node != list->tail) {
        swapValue = list->value[pos];
        list->value[pos] = list->value[node];
        list->value[node] = swapValue;

        node = list->next[node];
        pos++;
    }

    for (int i = 0; i < list->size; i++) {
        if (i > 0)
            list->next[i - 1] = i;
        if (i < list->maxsize - 1)
            list->prev[i + 1] = i;
    }
    list->head = 0;
    list->tail = list->size - 1;
    list->next[list->tail] = -1;
    list->prev[list->head] = -1;
}