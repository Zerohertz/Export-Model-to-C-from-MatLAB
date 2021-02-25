cfg = coder.config('lib');
cfg.TargetLang = 'C++';
cfg.DeepLearningConfig = coder.DeepLearningConfig('mkldnn');
cfg.GenCodeOnly(false);

codegen -args {testdat} -config cfg classifyX