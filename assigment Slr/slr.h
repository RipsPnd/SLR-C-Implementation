#ifndef SLR_H
#define SLR_H

#include <vector>

class slr {
private:
    double slope;       // beta_1
    double intercept;   // beta_0
    bool isFitted;

public:
    // Constructor
    slr();

    // Member functions
    void fit(const std::vector<double>& x, const std::vector<double>& y);
    double predict(double x) const;
    
    // Getters
    double getSlope() const;
    double getIntercept() const;
};

#endif