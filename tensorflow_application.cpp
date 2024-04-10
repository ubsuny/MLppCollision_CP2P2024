//Reconstruction of neutral B-meson.
//Applying selection criteria.
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <TChain.h>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TROOT.h>
#include <TSystem.h>

#include <tensorflow/core/public/session.h>
#include <tensorflow/core/platform/env.h>

void plotBpmassCP() {
    gSystem->Load("libPhysics");

    TChain* chain = new TChain("DecayTree");
    // Open the ROOT file
    //TFile* file = new TFile("B2HHH_MagnetUp.root", "READ");

    chain->Add("B2HHH_MagnetDown.root");
    chain->Add("B2HHH_MagnetUp.root");

    // Create variables to hold the branch data
    Int_t H1_isMuon, H1_Charge, H2_isMuon, H2_Charge, H3_isMuon, H3_Charge;

    Double_t H1_ProbK, H1_ProbPi, H1_PX, H1_PY, H1_PZ;

    Double_t H2_ProbK, H2_ProbPi, H2_PX, H2_PY, H2_PZ;

    Double_t H3_ProbK, H3_ProbPi, H3_PX, H3_PY, H3_PZ;

    // TensorFlow session
    tensorflow::Session* session;
    tensorflow::Status status = tensorflow::NewSession(tensorflow::SessionOptions(), &session);
    if (!status.ok()) {
        std::cerr << "Error creating TensorFlow session: " << status.ToString() << std::endl;
        return;
    }

    // Set branch addresses
    chain->SetBranchAddress("H1_ProbK", &H1_ProbK);
    chain->SetBranchAddress("H1_ProbPi", &H1_ProbPi);
    chain->SetBranchAddress("H1_isMuon", &H1_isMuon);
    chain->SetBranchAddress("H1_Charge", &H1_Charge);
    chain->SetBranchAddress("H1_PX", &H1_PX);
    chain->SetBranchAddress("H1_PY", &H1_PY);
    chain->SetBranchAddress("H1_PZ", &H1_PZ);
    chain->SetBranchAddress("H2_ProbK", &H2_ProbK);
    chain->SetBranchAddress("H2_ProbPi", &H2_ProbPi);
    chain->SetBranchAddress("H2_isMuon", &H2_isMuon);
    chain->SetBranchAddress("H2_Charge", &H2_Charge);
    chain->SetBranchAddress("H2_PX", &H2_PX);
    chain->SetBranchAddress("H2_PY", &H2_PY);
    chain->SetBranchAddress("H2_PZ", &H2_PZ);
    chain->SetBranchAddress("H3_ProbK", &H3_ProbK);
    chain->SetBranchAddress("H3_ProbPi", &H3_ProbPi);
    chain->SetBranchAddress("H3_isMuon", &H3_isMuon);
    chain->SetBranchAddress("H3_Charge", &H3_Charge);
    chain->SetBranchAddress("H3_PX", &H3_PX);
    chain->SetBranchAddress("H3_PY", &H3_PY);
    chain->SetBranchAddress("H3_PZ", &H3_PZ);

    // Create a histogram to store the Bplus masses
    TH1D* hist1 = new TH1D("hist1", "Mass of B+ and B-", 100, 5.00, 5.75);

    TH1D* hist2 = new TH1D("hist2", "Mass of B+ and B-", 100, 5.00, 5.75);

    // Loop over the events
    Int_t nEvents = chain->GetEntries();
    Int_t NBplus = 0;
    Int_t NBminus = 0;
    for (Int_t i = 0; i < nEvents; ++i) {
        // Get the event data
        chain->GetEntry(i);

        // TensorFlow calculation of square root
        tensorflow::Tensor x_tensor(tensorflow::DT_FLOAT, tensorflow::TensorShape());
        x_tensor.scalar<float>()() = H1_PX;

        // Run session to perform calculation
        std::vector<tensorflow::Tensor> output_tensors;
        const std::string input_tensor_name = "input";
        const std::string output_tensor_name = "output";
        status = session->Run({{input_tensor_name, x_tensor}}, {output_tensor_name}, {}, &output_tensors);
        if (!status.ok()) {
            std::cerr << "Error running TensorFlow session: " << status.ToString() << std::endl;
            return;
        }

        // Extract the result from the output tensor
        float square_root_result = output_tensors[0].scalar<float>()();

        // Print the result
        std::cout << "Square root of " << H1_PX << " is: " << square_root_result << std::endl;

        //cut#1: If B+ --> K+ K+ K-
        if (H1_ProbK >= 0.5 && H1_ProbPi < 0.25 && H1_isMuon == 0)
        {
            if (H2_ProbK >= 0.5 && H2_ProbPi < 0.25 && H2_isMuon == 0)
            {
                if (H3_ProbK >= 0.5 && H3_ProbPi < 0.25 && H3_isMuon == 0)
                {
                    if (H1_Charge + H2_Charge + H3_Charge == +1)
                    {
                        Double_t H1_P = sqrt(H1_PX * H1_PX + H1_PY * H1_PY + H1_PZ * H1_PZ);
                        Double_t H1_E = sqrt(H1_P * H1_P + 493.677 * 493.677);
                        Double_t H2_P = sqrt(H2_PX * H2_PX + H2_PY * H2_PY + H2_PZ * H2_PZ);
                        Double_t H2_E = sqrt(H2_P * H2_P + 493.677 * 493.677);
                        Double_t H3_P = sqrt(H3_PX * H3_PX + H3_PY * H3_PY + H3_PZ * H3_PZ);
                        Double_t H3_E = sqrt(H3_P * H3_P + 493.677 * 493.677);
                        TLorentzVector H1(H1_PX, H1_PY, H1_PZ, H1_E);
                        TLorentzVector H2(H2_PX, H2_PY, H2_PZ, H2_E);
                        TLorentzVector H3(H3_PX, H3_PY, H3_PZ, H3_E);
                        TLorentzVector Bp = H1 + H2 + H3;
                        NBplus = NBplus + 1;
                        float massBp_inv_GeV = Bp.M() / 1000.0;
                        hist1->Fill(massBp_inv_GeV);
                    }
                    //cut#1: If B- --> K+ K- K-
                    if (H1_Charge + H2_Charge + H3_Charge == -1)
                    {
                        Double_t H1_P = sqrt(H1_PX * H1_PX + H1_PY * H1_PY + H1_PZ * H1_PZ);
                        Double_t H1_E = sqrt(H1_P * H1_P + 493.677 * 493.677);
                        Double_t H2_P = sqrt(H2_PX * H2_PX + H2_PY * H2_PY + H2_PZ * H2_PZ);
                        Double_t H2_E = sqrt(H2_P * H2_P + 493.677 * 493.677);
                        Double_t H3_P = sqrt(H3_PX * H3_PX + H3_PY * H3_PY + H3_PZ * H3_PZ);
                        Double_t H3_E = sqrt(H3_P * H3_P + 493.677 * 493.677);
                        TLorentzVector H1(H1_PX, H1_PY, H1_PZ, H1_E);
                        TLorentzVector H2(H2_PX, H2_PY, H2_PZ, H2_E);
                        TLorentzVector H3(H3_PX, H3_PY, H3_PZ, H3_E);
                        TLorentzVector Bm = H1 + H2 + H3;
                        NBminus = NBminus + 1;
                        float massBm_inv_GeV = Bm.M() / 1000.0;
                        hist2->Fill(massBm_inv_GeV);
                    }
                }
            }
        }
    }

    // Close the TensorFlow session
    delete session;

    // Print out the number of B+ and B- decays
    std::cout << "Number of B+ decays = " << NBplus << "\n";
    std::cout << "Number of B- decays = " << NBminus << "\n";

    // Calculate the asymmetry
    Double_t A = static_cast<double>(NBminus - NBplus) / (NBminus + NBplus);
    std::cout << "Measured Asymmetry = " << A << "\n";

    // Calculate the uncertainty
    Double_t U = sqrt((1 - A * A) / (NBminus + NBplus));
    std::cout << "Measured Uncertainty = " << U << "\n";

    // Print the significance
    std::cout << "Significance = " << A / U << "\n";

    // Create a canvas and draw the histogram
    TCanvas* canvas = new TCanvas("canvas", "Bp Mass Canvas");

    hist1->SetFillStyle(3001);  // Transparent fill style
    hist1->SetFillColor(kBlue); // Blue fill color
    hist1->Draw();

    hist2->SetFillStyle(3001);    // Transparent fill style
    hist2->SetFillColor(kRed);    // Red fill color
    hist2->Draw("same");

    // Update the canvas
    canvas->Update();

    // Wait for user input to exit
    canvas->WaitPrimitive();

    // Close the file
    //file->Close();
}
