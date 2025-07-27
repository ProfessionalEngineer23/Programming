import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager

def get_salary_info(job_title, country="Ireland"):
    query = job_title.lower().replace(" ", "%20")
    url = f"https://www.levels.fyi/jobs?country={country}&query={query}"

    options = webdriver.ChromeOptions()
    options.add_argument('--headless')
    options.add_argument('--no-sandbox')
    options.add_argument('--disable-gpu')
    options.add_argument('--disable-dev-shm-usage')

    driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)
    driver.get(url)

    try:
        # Wait for at least one job card to appear (10 seconds max)
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, 'div[class*="card__"]'))
        )

        # Scroll to the bottom to load all cards
        driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
        time.sleep(2)

        data_cards = driver.find_elements(By.CSS_SELECTOR, 'div[class*="card__"]')

        results = []
        for card in data_cards:
            try:
                title = card.find_element(By.CSS_SELECTOR, 'div[class*="job-title"]').text
                comp = card.find_element(By.CSS_SELECTOR, 'div[class*="compensation"]').text
                company = card.find_element(By.CSS_SELECTOR, 'div[class*="company"]').text
                location = card.find_element(By.CSS_SELECTOR, 'div[class*="location"]').text

                if "Ireland" in location:
                    results.append({
                        "title": title,
                        "company": company,
                        "compensation": comp,
                        "location": location
                    })
            except Exception as e:
                print("Skipping card due to error:", e)
                continue

    except Exception as e:
        print("Error waiting for job cards:", e)
        driver.quit()
        return {"error": "Timeout waiting for salary data to load."}

    driver.quit()

    if results:
        entry = results[0]
        return {
            "title": entry["title"],
            "company": entry["company"],
            "location": entry["location"],
            "avg_salary": entry["compensation"],
            "source": "Levels.fyi"
        }
    else:
        return {"error": f"No salary data found for '{job_title}' in {country}"}

if __name__ == "__main__":
    print(get_salary_info("Backend Engineer", "Ireland"))

