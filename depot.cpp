#include "depot.h"
#include "stack.h"
#include <cstdio>

struct DepotImplementation
{
    Stack stack;
};

Depot create_depot()
{
  Depot d = (Depot)smalloc(sizeof(struct DepotImplementation));
  d->stack = create_stack();

  return d;
}

void delete_depot(Depot depot)
{
  delete_stack(depot->stack);
  sfree(depot);
}

void push_depot(Depot depot, Product *product)
{
  push_stack(depot->stack, product);
}

int get_count(Depot depot)
{
  return get_count(depot->stack)/STACK_SIZE_LIMIT + (get_count(depot->stack)% STACK_SIZE_LIMIT > 0 ? 1 : 0);
}

Product *pop_depot(Depot depot)
{
  return (Product*)pop_stack(depot->stack);
}
