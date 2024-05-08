# The yfinance library uses the stock symbols from Yahoo Finance. You can search for any publicly traded company’s stock symbol on the Yahoo Finance website.

# For example, if you want to look up Amazon, you would use the symbol AMZN. For Google, which is under the parent company Alphabet, you would use GOOGL. For Apple, you would use AAPL.

import yfinance as yf


class StockEvaluator:
    def __init__(self, stock):
        self.stock_info = yf.Ticker(stock).info
        self.earnings_growth = self.stock_info.get(
            'earningsQuarterlyGrowth', 0)
        self.revenue_growth = self.stock_info.get('revenueQuarterlyGrowth', 0)
        self.market_cap = self.stock_info.get('marketCap', 0)
        self.dividend_yield = self.stock_info.get(
            'trailingAnnualDividendYield', 0)

    def calculate_score(self):
        score = 0
        if self.earnings_growth > 0.05:
            score += 1
        if self.revenue_growth > 0.05:
            score += 1
        # if self.pe_ratio < 20:
        #     score += 1
        if self.market_cap > 1000000000000:
            score += 1
        if self.dividend_yield > 0.01:
            score -= 1
        return score

    def evaluate(self):
        score = self.calculate_score()
        if score >= 3:
            print("Score = ", score)
            print(
                f"{self.stock_info['symbol']} is a good buy (based on rule-based evaluation).")
        elif score == 2:
            print("Score = ", score)
            print(
                f"{self.stock_info['symbol']} is good to hold (based on rule-based evaluation).")
        else:
            print("Score = ", score)
            print(
                f"{self.stock_info['symbol']} is not a good buy (based on rule-based evaluation).")


while True:
    stock_symbol = input("Enter a stock symbol: ")
    evaluator = StockEvaluator(stock_symbol)
    evaluator.evaluate()

    x = input("Do you want to continue: (Y or N)")
    if x.lower() == "n":
        break
    elif x.lower() != "y":
        print("please enter valid input")


# # Define the knowledge base
# knowledge_base = {
#     "APPLE": {
#         "earnings_growth": 0.05,
#         "revenue_growth": 0.02,
#         "market_cap": 200000000000,
#         "dividend_yield": 0.01
#     },
#     "GOOGLE": {
#         "earnings_growth": 0.08,
#         "revenue_growth": 0.05,
#         "market_cap": 1200000000000,
#         "dividend_yield": 0.00
#     },
#     "AMAZON": {
#         "earnings_growth": 0.06,
#         "revenue_growth": 0.10,
#         "market_cap": 1500000000000,
#         "dividend_yield": 0.00
#     }
# }

# # Define the inference engine


# def evaluate_stock(stock):
#     score = 0
#     if knowledge_base[stock]["earnings_growth"] > 0.05:
#         score += 1
#     if knowledge_base[stock]["revenue_growth"] > 0.05:
#         score += 1
#     if knowledge_base[stock]["market_cap"] > 1000000000000:
#         score += 1
#     if knowledge_base[stock]["dividend_yield"] > 0.01:
#         score -= 1
#     if score >= 3:
#         print("Score = ", score)
#         print(f"{stock} is a good buy (based on rule-based evaluation).")
#     elif score >= 2 and score < 3:
#         print("Score = ", score)
#         print(f"{stock} is good to hold (based on rule-based evaluation).")
#         print("Score = ", score)
#         print("Score = ", score)
#         print(f"{stock} is not a good buy (based on rule-based evaluation).")


# while (True):
#     # Get user input
#     stock_symbol = input("Enter a stock symbol: ")

# # Test the system
#     evaluate_stock(stock_symbol)

#     x = input("Do you want to continue: (Y or N)")
#     if x == "Y" or x == 'y':
#         continue
#     elif x == "N" or x == 'n':
#         break
#     else:
#         print("please enter valid input")
