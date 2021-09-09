products = [["iphone", 6888], ["MacPro", 14800], [
    "小米6", 2499], ["Coffee", 31], ["Book", 60], ["Nike", 699]]
print("-"*6, " 商品列表 ", "-"*6)
i = 0
for product in products:
    print(i, end="   ")
    for element in product:
        print(element, end="\t")
    print("\n")
    i += 1
ch = 'c'
shopping_cart = []
while(1):
    ch = input("What r u goin' to buy?")
    if (ch == 'q'):
        break
    elif (ch >= '0' and ch <= '5'):
        shopping_cart.append(products[int(ch)])
i = 0
while(i < len(shopping_cart)):
    for element in shopping_cart[i]:
        print(element, end="\t")
    print("\n")
    i += 1