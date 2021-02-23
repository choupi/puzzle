
ingredient_set = set()
ingredient_dict = {}
allergen_dict = {}
with open('input') as f:
    for l in f:
        ingredients, allergens = l.strip().split(' (contains ', 1)
        ingredients = set(ingredients.split())
        ingredient_set = ingredient_set | ingredients
        for ing in ingredients:
            ingredient_dict[ing] = ingredient_dict.get(ing, 0) + 1
        allergens = allergens.strip(')').split(', ')
        for al in allergens:
            if al not in allergen_dict:
                allergen_dict[al] = ingredients
            else:
                allergen_dict[al] = allergen_dict[al] & ingredients
print(len(ingredient_set))
for al in allergen_dict:
    print(al, len(allergen_dict[al]))
    ingredient_set = ingredient_set - allergen_dict[al]
print(ingredient_set)
print(sum([ingredient_dict[ing] for ing in ingredient_set]))
