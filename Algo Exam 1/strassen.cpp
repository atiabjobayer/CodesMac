// optimized matrix multiplication using Strassen algorithm

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// size at which the sequential multiplication is used instead of recursive
// Strassen
int thresholdSize = 128;

void initMat(vector< vector< double > > &a, vector< vector< double > > &b,
             int n) {
    // initialize matrices and fill them with random values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = (double)rand() / RAND_MAX * 10;
            b[i][j] = (double)rand() / RAND_MAX * 10;
        }
    }
}

void multiplyMatStandard(vector< vector< double > > &a,
                         vector< vector< double > > &b,
                         vector< vector< double > > &c, int n) {
    // standard matrix multiplication: C <- C + A x B
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double temp = 0;
            for (int k = 0; k < n; ++k) {
                temp += a[i][k] * b[k][j];
            }
            c[i][j] = temp;
        }
    }
}

int getNextPowerOfTwo(int n) { return pow(2, int(ceil(log2(n)))); }

void fillZeros(vector< vector< double > > &newA,
               vector< vector< double > > &newB, vector< vector< double > > &a,
               vector< vector< double > > &b, int n) {
    // pad matrix with zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newA[i][j] = a[i][j];
            newB[i][j] = b[i][j];
        }
    }
}

void add(vector< vector< double > > &a, vector< vector< double > > &b,
         vector< vector< double > > &resultMatrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultMatrix[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract(vector< vector< double > > &a, vector< vector< double > > &b,
              vector< vector< double > > &resultMatrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultMatrix[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyStrassen(vector< vector< double > > &a,
                      vector< vector< double > > &b,
                      vector< vector< double > > &c, int n) {
    if (n <= thresholdSize) {
        multiplyMatStandard(a, b, c, n);
    }
    else {
        // expand and fill with zeros if matrix size is not a power of two
        int newSize = getNextPowerOfTwo(n);
        vector< vector< double > > newA(newSize, vector< double >(newSize)),
            newB(newSize, vector< double >(newSize)),
            newC(newSize, vector< double >(newSize));
        if (n == newSize) { // matrix size is already a power of two
            newA = a;
            newB = b;
        }
        else {
            fillZeros(newA, newB, a, b, n);
        }

        // initialize submatrices
        int blockSize = newSize / 2; // size for a partition matrix
        vector< double > block(blockSize);
        vector< vector< double > >
            /*partitions of newA*/
            a11(blockSize, block), a12(blockSize, block), a21(blockSize, block),
            a22(blockSize, block),
            /*partitions of newB*/
            b11(blockSize, block), b12(blockSize, block), b21(blockSize, block),
            b22(blockSize, block),
            /*partitions of newC*/
            c11(blockSize, block), c12(blockSize, block), c21(blockSize, block),
            c22(blockSize, block),
            /*matrices storing intermediate results*/
            aBlock(blockSize, block), bBlock(blockSize, block),
            /*set of submatrices derived from partitions*/
            m1(blockSize, block), m2(blockSize, block), m3(blockSize, block),
            m4(blockSize, block), m5(blockSize, block), m6(blockSize, block),
            m7(blockSize, block);

        // partition matrices
        for (int i = 0; i < blockSize; i++) {
            for (int j = 0; j < blockSize; j++) {
                a11[i][j] = newA[i][j];
                a12[i][j] = newA[i][j + blockSize];
                a21[i][j] = newA[i + blockSize][j];
                a22[i][j] = newA[i + blockSize][j + blockSize];
                b11[i][j] = newB[i][j];
                b12[i][j] = newB[i][j + blockSize];
                b21[i][j] = newB[i + blockSize][j];
                b22[i][j] = newB[i + blockSize][j + blockSize];
            }
        }

        // compute submatrices
        // m1 = (a11+a22)(b11+b22)
        add(a11, a22, aBlock, blockSize);
        add(b11, b22, bBlock, blockSize);
        multiplyStrassen(aBlock, bBlock, m1, blockSize);

        // m2 = (a21+a22)b11
        add(a21, a22, aBlock, blockSize);
        multiplyStrassen(aBlock, b11, m2, blockSize);

        // m3 = a11(b12-b22)
        subtract(b12, b22, bBlock, blockSize);
        multiplyStrassen(a11, bBlock, m3, blockSize);

        // m4 = a22(b21-b11)
        subtract(b21, b11, bBlock, blockSize);
        multiplyStrassen(a22, bBlock, m4, blockSize);

        // m5 = (a11+a12)b22
        add(a11, a12, aBlock, blockSize);
        multiplyStrassen(aBlock, b22, m5, blockSize);

        // m6 = (a21-a11)(b11+b12)
        subtract(a21, a11, aBlock, blockSize);
        add(b11, b12, bBlock, blockSize);
        multiplyStrassen(aBlock, bBlock, m6, blockSize);

        // m7 = (a12-a22)(b12+b22)
        subtract(a12, a22, aBlock, blockSize);
        add(b12, b22, bBlock, blockSize);
        multiplyStrassen(aBlock, bBlock, m7, blockSize);

        // calculate result submatrices
        // c11 = m1+m4-m5+m7
        add(m1, m4, aBlock, blockSize);
        subtract(aBlock, m5, bBlock, blockSize);
        add(bBlock, m7, c11, blockSize);

        // c12 = m3+m5
        add(m3, m5, c12, blockSize);

        // c21 = m2+m4
        add(m2, m4, c12, blockSize);

        // c22 = m1-m2+m3+m6
        subtract(m1, m2, aBlock, blockSize);
        add(aBlock, m3, bBlock, blockSize);
        add(bBlock, m6, c22, blockSize);

        // calculate final result matrix
        for (int i = 0; i < blockSize; i++) {
            for (int j = 0; j < blockSize; j++) {
                newC[i][j]                         = c11[i][j];
                newC[i][blockSize + j]             = c12[i][j];
                newC[blockSize + i][j]             = c21[i][j];
                newC[blockSize + i][blockSize + j] = c22[i][j];
            }
        }

        // remove additional values from expanded matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = newC[i][j];
            }
        }
    }
}

double calculateMean(vector< double > data, int size) {
    double sum = 0.0, mean = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }

    mean = sum / size;
    return mean;
}

int main(int argc, char *argv[]) {
    srand(time(0)); // seed for random number generation

    // number of sample size considered to evaluate average execution time
    int sampleSize = 10;
    int matSize    = 1000;
    double startTime;
    double elapsedTime;
    double standardMean;
    double strassenMean;

    // set threshold value if given by user
    if (argc > 1) {
        thresholdSize = atoi(argv[1]);
    }

    // vectors storing execution time values
    vector< double > standardTime(sampleSize);
    vector< double > strassenTime(sampleSize);

    for (int k = 0; k < sampleSize; k++) {
        // initialize vectors for matrices a, b, c: a*b = c
        vector< vector< double > > a(matSize, vector< double >(matSize)),
            b(matSize, vector< double >(matSize)),
            c(matSize, vector< double >(matSize));

        initMat(a, b, matSize);

        // standard execution
        startTime = time(0);
        multiplyMatStandard(a, b, c, matSize);
        elapsedTime     = time(0) - startTime;
        standardTime[k] = elapsedTime;

        // multiplication using Strassen's
        startTime = 0;
        startTime = time(0);
        multiplyStrassen(a, b, c, matSize);
        elapsedTime     = time(0) - startTime;
        strassenTime[k] = elapsedTime;
    }
    cout << "Standard multiplication" << endl;
    standardMean = calculateMean(standardTime, sampleSize);
    cout << "Average time taken to execute matrices of size - " << matSize
         << " : " << standardMean << endl;
    cout << endl;

    cout << "Multiplication using Strassen's" << endl;
    cout << "Threshold used: " << thresholdSize << endl;
    strassenMean = calculateMean(strassenTime, sampleSize);
    cout << "Average time taken to execute matrices of size - " << matSize
         << " : " << strassenMean << endl;
    cout << endl;

    cout << "Speed up gained by using Strassen's-" << matSize << " : "
         << standardMean / strassenMean << endl;
    cout << endl;

    return 0;
}
