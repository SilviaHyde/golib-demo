#include <LTemplate.h>

class Demo1 {
public:
	// basic example
	mint addTwo(mint a, mint b) { return a+b; }

	// trace of real matrix
	double trace(mma::RealMatrixRef mat) {
		if (mat.rows() != mat.cols())
			throw mma::LibraryError("trace: Square matrix expected.");
		double sum = 0.0;
		for (mint i=0; i < mat.rows(); ++i) {
			sum += mat(i,i);
			mma::check_abort(); // allow for user aborts
		}
		return sum;
	}
};