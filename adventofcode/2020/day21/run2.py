
ingredient_map = []
allergen_dict = {}
with open('input') as f:
    for l in f:
        ingredients, allergens = l.strip().split(' (contains ', 1)
        ingredients = set(ingredients.split())
        allergens = allergens.strip(')').split(', ')
        for al in allergens:
            if al not in allergen_dict:
                allergen_dict[al] = ingredients
            else:
                allergen_dict[al] = allergen_dict[al] & ingredients
for al in allergen_dict:
    print(al, len(allergen_dict[al]))
for i in range(len(allergen_dict)):
    min_al = ''
    min_n = float('inf')
    for al in allergen_dict:
        if len(allergen_dict[al]) < min_n:
            min_al = al
            min_n = len(allergen_dict[al])
    if min_n != 1:
        print('!!!!!!!!!!!!!!!!')
    ing = allergen_dict[min_al].pop()
    ingredient_map.append((min_al, ing))
    del allergen_dict[min_al]
    for al in allergen_dict:
        if ing in allergen_dict[al]:
            allergen_dict[al].remove(ing)
print(ingredient_map)
print(','.join([ing[1] for ing in sorted(ingredient_map)]))
