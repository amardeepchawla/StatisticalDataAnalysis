// Program to illustrate use of ROOT random number and histogram classes
// Glen Cowan, RHUL, Physics, November 2007

#include <iostream>
#include <cmath>
#include <TH1D.h>
#include <TFile.h>
#include <TRandom3.h>

using namespace std;

int main(){

// Open output file (apparently needs to be done before booking)
  TFile* file = new TFile("simpleMC.root", "recreate");

// Book histograms
  TH1D* h_Uni = new TH1D("h_Uni", "uniform random numbers",  100,  0, 1.0);
  TH1D* h_Exp = new TH1D("h_Exp", "exponential random numbers",  100,  0, 5.0);

  // Define histograms
  TH1D* h_1 = new TH1D("h_1", "sequence one", 100, 0., 1.0);
  TH1D* h_2 = new TH1D("h_2", "sequence two", 100, 0., 5.0);
  TH1D* h_3 = new TH1D("h_3", "sequence three", 100, 0., 5.0);

// Create a TRandom3 object to generate random numbers
  int seed = 12345;
  TRandom3* ran = new TRandom3(seed);

// Generate some random numbers and fill histograms
  const int numValues = 10000;
  const double xi = 1.0;                // mean of exponential pdf
  double n[numValues];

  for (int i=0; i<numValues; ++i){
    double r = ran->Rndm();             // uniform in [0,1]
    double x = - xi * log(r);
    h_Uni->Fill(r);
    h_Exp->Fill(x);
    n[i] = r;
  }

for(int i=0; i<numValues-1; ++i){
  double x1 = n[i] + n[i+1] -1;
  h_1->Fill(x1);
  }

for(int i=0; i<numValues-3; ++i){
    double x2 = n[i] + n[i+1] + n[i+2] + n[i+3] - 2;
    h_2->Fill(x2);
  }

for(int i=0; i<numValues-11; ++i){
    double x_3 = n[i];
    for(int j=0; j<12; j++){
      x_3 += n[i+j];
    }
    h_3->Fill(x_3-6);
  }

// Store all histograms in the output file and close up
  file->Write();
  file->Close();

  return 0;
}
