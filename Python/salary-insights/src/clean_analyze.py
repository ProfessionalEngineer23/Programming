# clean_analyze.py
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import ast  # to safely convert string to list

def analyze_data():
    df = pd.read_csv("../data/remoteok_jobs.csv")

    # Clean and prepare the 'tags' column
    df['tags'] = df['tags'].fillna('[]').apply(ast.literal_eval)

    # Explode the list of tags into separate rows
    all_tags = df.explode('tags')

    # Count most frequent tags
    top_tags = all_tags['tags'].value_counts().head(10)

    # Plot
    plt.figure(figsize=(10, 6))
    sns.barplot(x=top_tags.values, y=top_tags.index, palette='viridis')
    plt.title("Top 10 Most Common Remote Tech Tags (RemoteOK)")
    plt.xlabel("Number of Job Listings")
    plt.ylabel("Tag")
    plt.tight_layout()
    plt.savefig("../visuals/top_tags.png")
    plt.show()

if __name__ == "__main__":
    analyze_data()
