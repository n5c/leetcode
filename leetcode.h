#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#ifndef LEETCODE_H
#define LEETCODE_H


/**
 * Defintion for singly-linked list.
 */
struct ListNode
{
	int val;
	struct ListNode *next;
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define bool int
#define true 1
#define false 0

#endif

