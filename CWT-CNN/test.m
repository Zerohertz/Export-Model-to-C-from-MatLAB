load('test');
testdat = cwt(test);
IMG = uint8(mat2gray(abs(testdat))*255);
GryMat = imresize(IMG, [28 28]);
label = classifyX(GryMat);