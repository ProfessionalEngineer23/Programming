# -----------------------------------------
# Import necessary modules
# -----------------------------------------
from flask import Flask, render_template, request, jsonify
from Maths.mathematics import summation, subtraction, multiplication

# -----------------------------------------
# Create a new Flask app instance
# -----------------------------------------
app = Flask("Mathematics Problem Solver")


# -----------------------------------------
# Route: /sum
# Description: Adds two numbers passed as query parameters
# Example usage: /sum?num1=3&num2=5
# -----------------------------------------
@app.route("/sum")
def sum_route():
    try:
        num1_raw = request.args.get('num1')
        num2_raw = request.args.get('num2')

        # Attempt to convert inputs to float
        num1 = float(num1_raw)
        num2 = float(num2_raw)

        # Perform addition using custom function
        result = summation(num1, num2)

        # If result is a whole number, return as integer
        if result.is_integer():
            result = int(result)

        return str(result)

    except (TypeError, ValueError):
        # Return 400 for invalid inputs like non-numerical values
        return jsonify({"message": "Invalid input: Please enter numeric values"}), 400


# -----------------------------------------
# Route: /sub
# Description: Subtracts second number from the first
# Example usage: /sub?num1=10&num2=4
# -----------------------------------------
@app.route("/sub")
def sub_route():
    try:
        num1_raw = request.args.get('num1')
        num2_raw = request.args.get('num2')

        num1 = float(num1_raw)
        num2 = float(num2_raw)
        result = subtraction(num1, num2)

        if result.is_integer():
            result = int(result)

        return str(result)

    except (TypeError, ValueError):
        return jsonify({"message": "Invalid input: Please enter numeric values"}), 400


# -----------------------------------------
# Route: /mul
# Description: Multiplies two numbers passed as query parameters
# Example usage: /mul?num1=3&num2=7
# -----------------------------------------
@app.route("/mul")
def mul_route():
    try:
        num1_raw = request.args.get('num1')
        num2_raw = request.args.get('num2')

        num1 = float(num1_raw)
        num2 = float(num2_raw)
        result = multiplication(num1, num2)

        if result.is_integer():
            result = int(result)

        return str(result)

    except (TypeError, ValueError):
        return jsonify({"message": "Invalid input: Please enter numeric values"}), 400


# -----------------------------------------
# Route: /
# Description: Serves the index HTML template as home page
# -----------------------------------------
@app.route("/")
def render_index_page():
    return render_template('index.html')


# -----------------------------------------
# Route: /test500
# Description: Deliberately raises an exception to test error handling
# -----------------------------------------
@app.route("/test500")
def test500():
    raise Exception("Forced exception for testing")


# -----------------------------------------
# Global Error Handler: 404 Not Found
# Triggered when a route does not exist
# -----------------------------------------
@app.errorhandler(404)
def api_not_found(error):
    return jsonify({"message": "API not found"}), 404


# -----------------------------------------
# Global Error Handler: 500 Internal Server Error
# Catches any uncaught exception and returns a JSON error
# -----------------------------------------
@app.errorhandler(Exception)
def handle_exception(e):
    return jsonify({"message": str(e)}), 500


# -----------------------------------------
# Run the Flask app locally on port 8080
# Accessible via http://localhost:8080
# -----------------------------------------
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8080)
