# Analysis of Higgs Decay into Two Z-Bosons and 4 Leptons

In this analysis, we investigated the decay of the Higgs boson into two Z-bosons, each of which subsequently decays into two leptons (4 leptons in total). The goal was to distinguish between signal events (Higgs boson decay) and background events (other processes that mimic the signal) based on certain observables.

## Data

We utilized data samples obtained from the HZZ4LeptonsAnalysis, containing events of Higgs decay into two Z-bosons and 4 leptons. The data was divided into two categories:
- Background: Events from processes other than Higgs decay that can mimic the signal.
- Signal (VV): Events representing the decay of the Higgs boson into two Z-bosons.

## Methodology

To separate the signal from the background, we employed the XGBoost (Extreme Gradient Boosting) algorithm, which is a powerful machine learning technique for classification tasks.

### XGBoost (BDT)

We trained an XGBoost classifier using the provided features (observables) from the data samples. The classifier was trained to distinguish between signal and background events based on the observed features. By optimizing the model's performance, we aimed to achieve a clear separation between the signal and background data points.

## Computing Environment

For this analysis, we utilized the CMS LPC (Large Hadron Collider Physics Center) environment instead of Docker. The CMS LPC environment offers several advantages for particle physics analysis:

1. **Access to CMS Data**: The LPC environment provides direct access to the CMS experiment's data and computing resources, facilitating efficient analysis workflows.

2. **Specialized Software Stacks**: It comes with pre-installed software stacks tailored for CMS analysis, including ROOT, CMSSW, and various analysis tools, making it easy to set up and run particle physics analyses.

3. **High-Performance Computing**: LPC resources offer high-performance computing capabilities optimized for particle physics workloads, allowing for faster data processing and analysis.

4. **Community Support**: Being part of the CMS collaboration, LPC provides access to a large community of researchers and experts who can provide support and guidance for analysis tasks.

Using the CMS LPC environment streamlines the analysis process and ensures compatibility with CMS collaboration standards and resources.

## Conclusion

Using the XGBoost classifier in the CMS LPC environment, we were able to build a Boosted Decision Tree (BDT) model that effectively separates signal events (Higgs decay) from background events. This analysis contributes to the understanding of the Higgs boson decay process and helps in identifying key observables that can discriminate between signal and background events.
