#ifndef BAZA_H
#define BAZA_H

#include <stdio.h>
#include <stdlib.h>

#endif //BAZA_H


#ifndef STRUCT_H
#define STRUCT_H

#include "struct.h"

#endif //STRUCT_H


#ifndef CREATE_H
#define CREATE_H

#include "create.h"

#endif //CREATE_H


// �������� ���� �� ����
void removeNode(Cache* cache, CacheNode* node);

// ������� ���� � ������ ����
void insertHead(Cache* cache, CacheNode* node);

// ���������� ������� ������������� ����
void updateFrequency(Cache* cache, CacheNode* node);

// ������� ������ �������� � ���
void put(Cache* cache, int key, int value);

// ��������� �������� �� ����� �� ����
int get(Cache* cache, int key);

//������� ����� ��������� � ���
int LFUCacheHits(int capacity, int n, int* requests);
