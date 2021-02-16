function label = classifyX(X)
CompactMdl = loadLearnerForCoder('Model');
label = predict(CompactMdl, X);
end

