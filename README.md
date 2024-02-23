# ROOT Data Types for Particle Physics Analysis in C++

This document provides an overview of the ROOT data types commonly used in particle physics analysis with C++.

## ROOT

ROOT is a data analysis framework developed at CERN, widely used in particle physics research. It provides a set of tools for data storage, analysis, and visualization.

## Data Types

### TTree

- **Description**: TTree is a data structure for storing hierarchical data in ROOT files. It organizes data into branches, with each branch representing a variable or object.
- **Usage**: TTree is commonly used to store event data, such as particle properties, detector signals, or simulation outputs.

### TBranch

- **Description**: TBranch represents a branch in a TTree. It contains the data associated with a specific variable or object.
- **Usage**: TBranch allows access to individual data elements within a TTree, facilitating data retrieval and analysis.
  
![Screenshot 2024-02-23 103655](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/aa644036-c197-4ee1-9bee-7087edd50bc4)

### TLorentzVector

- **Description**: TLorentzVector is a class for representing four-vectors, commonly used in relativistic physics. It stores momentum and energy components.
- **Usage**: TLorentzVector is extensively used in particle physics for representing particle kinematics, such as momentum, energy, and mass.

### TFile

- **Description**: TFile is a ROOT class for managing ROOT file I/O operations. It provides functionalities for creating, opening, and writing to ROOT files.
- **Usage**: TFile is used to read and write ROOT files containing TTree and other ROOT objects.

### TCanvas

- **Description**: TCanvas is a ROOT class for creating graphical canvases for plotting and visualization.
- **Usage**: TCanvas provides a platform for generating plots, histograms, and graphical representations of data stored in ROOT files.

### TH1, TH2, TH3

- **Description**: TH1, TH2, and TH3 represent one-dimensional, two-dimensional, and three-dimensional histograms, respectively.
- **Usage**: These classes are used for histogramming and visualizing data distributions in various dimensions.

### TGraph, TGraphErrors, TGraphAsymmErrors

- **Description**: TGraph, TGraphErrors, and TGraphAsymmErrors represent graphs with or without errors in ROOT.
- **Usage**: These classes are used to visualize and analyze graph-based data, such as experimental measurements or theoretical predictions.

### Example C++ code and plot using ROOT file (Reconstructed mass of B-meson)

![Screenshot 2024-02-23 104322](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/d48761de-6454-476c-bb7f-2d945d4fa565)

![Screenshot 2024-02-23 104109](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/dc24a4a9-1e0a-4cd4-8904-2d908e2a796a)

### Task for current project.

- For this project, I want to perform a similar analysis but using Machine Learning algorithm. In the example above, for and if loops were used to separate the signal from the background from a ROOT file.


# Adding PyTorch Feature to GitHub Codespace

This guide outlines the steps to customize a GitHub Codespace by adding the "PyTorch" feature:

## Step 1: Create Devcontainer Folder and JSON File

- Create a folder named `.devcontainer` in your GitHub repository.
- Inside the `.devcontainer` folder, create a `devcontainer.json` file (This will help launch codespace).

## Step 2: Launch GitHub Codespace

- Launch a new GitHub Codespace from your repository.
- Select the option to create a new Codespace with your custom configuration.

## Step 3: Add PyTorch Feature

- Add the "PyTorch" feature to the configuration.
- "Pytorch" is a Machine Learning (ML) framework

## Step 4: Commit the Change

- After adding the PyTorch feature, commit the modifications to your local repository.

## Step 5: Push Changes to Main Repository

- Push the committed changes to the main branch of your GitHub repository.
- This ensures that the updated `devcontainer.json` file is available for future Codespace launches.

Following these steps will enable you to incorporate the PyTorch feature into your GitHub Codespace, providing a tailored environment for your development needs.

