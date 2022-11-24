//
// Created by fsindustry on 2022/11/24.
//

/**
 * 定义 Key 类型
 */
typedef int KEY_TYPE;

/**
 * 定义通用的红黑树节点
 */
#define RBTREE_ENTRY(name, type) \
    struct name {                \
        struct type *right; \
        struct type *left; \
        struct type *parent; \
        unsigned char color; \
    }

/**
 * 定义红黑树的节点
 */
typedef struct _rbtree_node {

    /* 红黑树的业务属性，变化较大 */
    KEY_TYPE key; // 查找key
    void *value; // 查找value

    /* 红黑树的性质属性，基本不变 */
    RBTREE_ENTRY(, _rbtree_node);
} rbtree_node;

/**
 * 定义红黑树
 */
typedef struct _rbtree {
    struct _rbtree_node *root; // 根节点
    struct _rbtree_node *nil; // 空节点，用于给空的左右子树占位；
} rbtree;

/**
 * 左旋
 * @param T
 * @param x
 */
void rbtree_left_rotate(rbtree *T, rbtree_node *x) {
    rbtree_node *y = x->right;
}