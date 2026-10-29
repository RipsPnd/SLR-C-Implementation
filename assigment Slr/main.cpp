#include <iostream>
#include <vector>
#include <iomanip>
#include "slr.cpp"

int main() {
    // Hardcoded dataset based on the provided table:
    // Independent variable (x): Advertising (Million Euro)
    std::vector<double> advertising = {23, 26, 30, 34, 43, 48, 52, 57, 58};
    
    // Dependent variable (y): Sales (Million Euro)
    std::vector<double> sales = {651, 762, 856, 1063, 1190, 1298, 1421, 1440, 1518};

    // Instantiate and fit the model
    slr model;
    model.fit(advertising, sales);

    // Print calculated parameters
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "--- Simple Linear Regression Results ---" << std::endl;
    std::cout << "Slope (beta_1)    : " << model.getSlope() << std::endl;
    std::cout << "Intercept (beta_0): " << model.getIntercept() << std::endl;
    std::cout << "\nRegression Equation: Sales = " 
              << model.getSlope() << " * Advertising + " << model.getIntercept() << std::endl;

    // Example prediction
    double testAd = 40.0; // Predict Sales for 40 Million Euros of Advertising
    std::cout << "\nPredicted Sales for " << testAd << " Million Euro in Advertising: " 
              << model.predict(testAd) << " Million Euro" << std::endl;

    return 0;
}