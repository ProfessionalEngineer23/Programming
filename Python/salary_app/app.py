from flask import Flask, render_template, request, jsonify
from salary_lookup import get_salary_info

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/get-salary", methods=["POST"])
def get_salary():
    data = request.get_json()
    job_title = data.get("job_title")
    country = data.get("country", "Ireland")

    result = get_salary_info(job_title, country)
    return jsonify(result)

if __name__ == "__main__":
    app.run(debug=True)
