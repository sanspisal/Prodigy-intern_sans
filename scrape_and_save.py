import requests
from bs4 import BeautifulSoup
import csv

def scrape_product_info(url):
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'}
    
    # Send a GET request to the URL
    response = requests.get(url, headers=headers)

    # Check if the request was successful (status code 200)
    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')

        # Extract product information (replace these with the actual HTML tags on the target website)
        product_names = [name.text.strip() for name in soup.find_all('h2', class_='product-name')]
        product_prices = [price.text.strip() for price in soup.find_all('span', class_='product-price')]
        product_ratings = [rating.text.strip() for rating in soup.find_all('span', class_='product-rating')]

        return list(zip(product_names, product_prices, product_ratings))
    else:
        print(f"Failed to retrieve the page. Status code: {response.status_code}")
        return None

def save_to_csv(data, filename='product_data.csv'):
    with open(filename, 'w', newline='', encoding='utf-8') as csvfile:
        fieldnames = ['Product Name', 'Price', 'Rating']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

        writer.writeheader()
        for row in data:
            writer.writerow({'Product Name': row[0], 'Price': row[1], 'Rating': row[2]})

if __name__ == "__main__":
    # Replace the URL with the target e-commerce website
    target_url = 'https://example.com/products'
    
    product_data = scrape_product_info(target_url)

    if product_data:
        save_to_csv(product_data)
        print("Product information has been successfully scraped and saved to product_data.csv.")
    else:
        print("Failed to scrape product information.")