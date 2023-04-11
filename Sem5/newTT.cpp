#include <stdlib.h>
#include <stdio.h>

struct struct_Tree;
struct struct_Unit;



typedef struct struct_Unit
{
    int data;
    struct_Unit* l_leaf;
    struct_Unit* r_leaf;
    struct_Unit* parent;
    struct_Tree* tree;
}Unit;

typedef struct struct_Tree
{
    int size;
    Unit *top;
}Tree;



void printTree(Tree inst_tree, Unit* actual_unit)
{   
    if (inst_tree.top == actual_unit)
        printf("%d ", inst_tree.size);
    printf("%d ", 1);
    if(actual_unit->l_leaf != NULL)
        printTree(inst_tree, actual_unit->l_leaf);
    else
    {
        printf("%d ", 0);
    }
    if(actual_unit->r_leaf != NULL)
            printTree(inst_tree, actual_unit->r_leaf);
    else{   
        printf("%d ", 0);     

    }
    return;  
}

Unit * create_unit(Unit* parent_unit, int data, Tree* tree)
{
    Unit* inst_unit = (Unit*)calloc(1, sizeof(Unit));
    inst_unit->tree = tree;
    inst_unit->l_leaf = NULL;
    // printf("l_leaf DONE!\n");
    inst_unit->r_leaf = NULL;
    // printf("r_leaf DONE!\n");
    inst_unit->parent = parent_unit;
    // printf("parent DONE!\n");
    inst_unit->data = data;
    // printf("data DONE!\n");
    inst_unit->tree->size += 1;
    // printf("size DONE!\n");
    return inst_unit;
}

Tree * from_order_to_tree(int* pre_ord, int* in_ord, int expected_tree_size)
{
    Tree* inst_tree = (Tree*)calloc(1, sizeof(Tree));
    inst_tree->size = 0;
    inst_tree->top = NULL;
    inst_tree->top = create_unit(inst_tree->top, pre_ord[0], inst_tree);
    Unit* tmp_unit = inst_tree->top;
    int left_direction = 1;
    int right_direction = 0;
    int i_pre_ord = 1;
    int i_in_ord = 0;
    while(inst_tree->size != expected_tree_size)
    {
        if(pre_ord[i_pre_ord] != in_ord[i_in_ord])
        {   
            tmp_unit->l_leaf = create_unit(tmp_unit, pre_ord[i_pre_ord], inst_tree);
            Unit* tmp_unit = inst_tree->top;
            i_pre_ord++;

        }
    }
    
}

int main()
{
    Tree inst_tree;
    inst_tree.size = 0;
    inst_tree.top = NULL;
    int * inorder;
    int* preorder;
    int len;
    scanf("%d", &len);

    inorder = (int*)calloc(len, sizeof(int));
    preorder = (int*)calloc(len, sizeof(int));

    for (int i = 0; i < len; i++)
    {
        scanf("%d", inorder + i);
    }
    for (int i = 0; i < len; i++)
    {
        scanf("%d", preorder + i);
    }



    inst_tree.top = create_unit(inst_tree.top, 4, &inst_tree);
    Unit * unit_4 = inst_tree.top;
    unit_4->l_leaf = create_unit(unit_4, 3, &inst_tree);
    Unit * unit_3 = unit_4->l_leaf;
    unit_3->l_leaf = create_unit(unit_3, 1, &inst_tree);
    Unit * unit_1 = unit_3->l_leaf;
    unit_4->r_leaf = create_unit(unit_4, 0, &inst_tree);
    Unit * unit_0 = unit_4->r_leaf;
    unit_0->l_leaf = create_unit(unit_0, 2, &inst_tree);
    Unit * unit_2 = unit_0->l_leaf;
    printf("create_unit() DONE!\n");
    printTree(inst_tree, inst_tree.top);
 
    return 0;
}



