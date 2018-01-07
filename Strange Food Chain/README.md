# Strange Food Chain

[spoj](http://www.spoj.com/problems/CHAIN/)

### Description
To solve the problem, we exploit a disjoint set data structure, let's call it `set`. In `set` we keep the following informations:

* The list of the elements of the set, with informations on the parent and on the rank (as in the usual disjoint set);
* Informations on who eats who (the `eat` vector);
* Informations on who is eaten by who (the `eaten` vector).

For every piece of information in input, we unify two elements of the set (type 1) or we store in `eat` the fact that `x` eats `y` and in `eaten` the fact that `y` is eaten by `x`. Since we use a disjoint set, we store changes only for the representatives of the various groups, so for example if the element `x` eats `y`, `z` and `w`, we know that `y`, `z` and `w` belong to the same group, so all of them have the same representative, let it be `y`, so we store only `eat[x] = y` and `eaten[y] = x`.

We have two distinct type of input:

1. `x` and `y` belong to the same group;
2. `x` eats `y`.

In the first case, we unify the representatives of the elements `x` and `y`, so one of the two becomes the new representative for that group. First we have to check if the given information si false. To do this, we check if one of the following conditions holds:

- `x` eats `y`;
- `y` eats `x`;
- `x` eats `c` that eats `y`;
- `y` eats `d` that eats `x`.

If any of this conditions holds, the information is false. Otherwise, since `x`and `y` belong to the same set, this means that `a = eat[x]` and `b = eat[y]` also belong to the same set, and the same is true for `c = eaten[x]` and `d = eaten[y]`.  
If `a` or `b` is `-1`, this means that `x` or `y` doesn't eat anyone, so we just need to update the negative value with the non negative one (if it exists). If they both are non negative, we unify the two elements and we update `eat[representative(x)] = representative(eat[x])`. The same is done with the `eaten` values. In this way, we don't lose informations on the representative, but we always enrich them.  
Another possibilities is that we have just one element `a` that eats `x` (or `y`) and just one element `b` eaten by `y` (or `x`); in this case, we have a chain of three elements, so we add the information that `b` eats `a` and we close the chain.

#### Example unify
In this example we represent with an arrow the fact that an element eats another element and with a dotted line the unify operation that we have to do. The first image represents the initial situation, while the second one represents the situation after the unify of x and y. This operation works because we assume that every chain of three elements is closed, and we assure this property both in the unify operation that in the eat one.


![unify](https://github.com/t-costa/CPC-Problems/blob/master/Strange%20Food%20Chain/unify.png)
![unify2](https://github.com/t-costa/CPC-Problems/blob/master/Strange%20Food%20Chain/unify%202.png)


In the second case, we have to modify the values of `eat` of the representative of `x` and of the representative of `eaten` of `y`. First we check if the operation is feasible, so we have to check that the following conditions don't hold:

- `x` and `y` belong to the same group;
- `y` eats `x`.

Otherwise, the operation is valid, so let `a = eaten[x]`, `b = eat[x]`, `c = eaten[y]`, `d = eat[y]`, we can deduce that `b` and `y` belong to the same set


![new_eater](https://github.com/t-costa/CPC-Problems/blob/master/Strange%20Food%20Chain/new_eater.png)
![new_eater2](https://github.com/t-costa/CPC-Problems/blob/master/Strange%20Food%20Chain/new_eater%202.png)

### Complexity
