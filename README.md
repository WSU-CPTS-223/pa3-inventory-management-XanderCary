[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.

# Thought process of implimentations 

For the data structures I am going to use two hash tables, one an open hash that will have the index be by category 
and add a single item to multiple indexs so it appears in all of its categorys list

The second will be a close hash using its id number so we have O(1) look up and insert times

My next problem to think about will be collision handeling and resizing but I want to get started writting the above before then so I get a feel for it. I have realized I need to think about this now because I need my array so because std::hash.

Finished all of the Dynamic Array functions now I am starting to get into the hash table but I am going to create the product struct first while its on my mind, I imagine I will need have an idea of how that will look when I start defining my Hash Table functions

In the struct I am deciding to do another dynamic array of all of the product categories I am going to use that to loop through
when I am adding the product to all of its categorys indexes if that is the right wording for it

Now defining the HashTable functions; currently regretting putting dynamic array and hash table in the same files they are just big now and it makes me sad about poor design.

While making the find for the HashTable I have decided I think that using an open hash for both uniq id look up and category find becuase it seems a lot easier to impliment instead of having to worry about probing 