class Product:
    def __init__(self, name, retail_price, purchase_price):
        self.name = name
        self.retail_price = retail_price
        self.purchase_price = purchase_price

    @property
    def profit(self):
        return self.retail_price - self.purchase_price

    @staticmethod
    def average_price(prices=None):
        if not prices:
            return 0
        return sum(prices) / len(prices)

    @property
    def information(self):
        return f"Товар: {self.name}, розничная цена: {self.retail_price}, закупочная цена: {self.purchase_price}"

