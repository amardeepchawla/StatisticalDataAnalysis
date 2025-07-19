// Simple ROOT macro to plot a pair of histogram.
// Modify arguments as needed.
// To execute, type .X plot2Hist.C
{

  // Set some defaults
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetCanvasBorderMode(0); // turn off canvas borders

  // Open the file and list its contents
  TFile* f = new TFile("simpleMC.root");
  f->ls();

  // Get a couple of histograms
  //TH1D* h1 = (TH1D*)f->Get("h_Uni");
  //TH1D* h2 = (TH1D*)f->Get("h_Exp");

  TH1D* h_1 = (TH1D*)f->Get("h_1");
  TH1D* h_2 = (TH1D*)f->Get("h_2");
  TH1D* h_3 = (TH1D*)f->Get("h_3");

  // Create a canvas, divide into two windows,
  TCanvas *c1 = new TCanvas("c1", "Canvas 1", 400, 10, 600, 700);
  c1->Divide(1,3);

  c1->cd(1); h_1->SetMaximum(h_1->GetMaximum()+20); h_1->SetXTitle("x"); h_1->SetYTitle("Sequence 1"); h_1->Draw();
  c1->cd(2); h_2->SetMaximum(h_2->GetMaximum()+20); h_2->SetXTitle("x"); h_2->SetYTitle("Sequence 2"); h_2->Draw();
  c1->cd(3); h_3->SetMaximum(h_3->GetMaximum()+20); h_3->SetXTitle("x"); h_3->SetYTitle("Sequence 3"); h_3->Draw();
}
