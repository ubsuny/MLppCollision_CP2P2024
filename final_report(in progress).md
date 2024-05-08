# Analysis of Higgs Decay into Two Z-Bosons and 4 Leptons

In this analysis, we investigated the decay of the Higgs boson into two Z-bosons, each of which subsequently decays into two leptons (4 leptons in total). The goal was to distinguish between signal events (Higgs boson decay) and background events (other processes that mimic the signal) based on certain observables.

## Data

We utilized data samples obtained from the HZZ4LeptonsAnalysis, containing events of Higgs decay into two Z-bosons and 4 leptons. The data was divided into two categories:
- Background: Events from processes other than Higgs decay that can mimic the signal.
- Signal (VV): Events representing the decay of the Higgs boson into two Z-bosons.

## Methodology

To separate the signal from the background, we employed the XGBoost (Extreme Gradient Boosting) algorithm, which is a powerful machine learning technique for classification tasks.

 1. Split the data into input features (X) and target labels (Y). X= f_massjj,f_mass4l Y=1,0 (Signal or background).
 2. Split the data into training and testing datasets.
 3. Define the model: boosted decision tree model from the xgboost library used.
 4. Run the training.
 5. Verify plot performance (ROC curve)
 6. Plot the decision boundary between signal and background events using the input features (f_massjj and 
f_mass4l)

### XGBoost (BDT)

We trained an XGBoost classifier using the provided features (observables) from the data samples. The classifier was trained to distinguish between signal and background events based on the observed features. By optimizing the model's performance, we aimed to achieve a clear separation between the signal and background data points.

## Computing Environment

For this analysis, we utilized the CMS LPC (Large Hadron Collider Physics Center) environment instead of Docker. The CMS LPC environment offers several advantages for particle physics analysis:

1. **Access to CMS Data**: The LPC environment provides direct access to the CMS experiment's data and computing resources, facilitating efficient analysis workflows.

2. **Specialized Software Stacks**: It comes with pre-installed software stacks tailored for CMS analysis, including ROOT, CMSSW, and various analysis tools, making it easy to set up and run particle physics analyses.

3. **High-Performance Computing**: LPC resources offer high-performance computing capabilities optimized for particle physics workloads, allowing for faster data processing and analysis.

4. **Community Support**: Being part of the CMS collaboration, LPC provides access to a large community of researchers and experts who can provide support and guidance for analysis tasks.

Using the CMS LPC environment streamlines the analysis process and ensures compatibility with CMS collaboration standards and resources.

## Data visualization

We used ROOT file for Higgs decay to two Z-bosons and 4 leptons. We have plotted the jet masses using **uproot** and **matplotlib**. We can see that the background and signal is overlapping for Z boson jets. Using **Xgboost** (a machine learning algorithm) we separate background and signal data points. 

![Screenshot 2024-05-08 192020](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/3bcb526c-718c-4037-b743-3f75776c4145)

## Decision Boundary Plot

The decision boundary plot allows us to visualize how the model distinguishes between signal and background events based on these input features. This visualization helps us understand the classification behavior of the model and identify regions where it may struggle to make accurate predictions.

![Screenshot 2024-05-08 192046](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/4fbabfa2-6263-47cf-9e51-eb309347fed2)


## Conclusion

Using the XGBoost classifier in the CMS LPC environment, we were able to build a Boosted Decision Tree (BDT) model that effectively separates signal events (Higgs decay) from background events. This analysis contributes to the understanding of the Higgs boson decay process and helps in identifying key observables that can discriminate between signal and background events.
