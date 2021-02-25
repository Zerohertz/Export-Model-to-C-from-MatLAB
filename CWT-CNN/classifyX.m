function label = classifyX(X)
persistent net
if isempty(net)
    net = coder.loadDeepLearningNetwork('net.mat');
end
%cfs = cwt(X);
%IMG = uint8(mat2gray(abs(X))*255);
%GryMat = imresize(IMG, [28 28]);
label = classify(net, X);
end

