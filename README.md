# 基于Simulink的BMS模型开发与代码生成学习项目

## 1. 项目简介

这是一个基于开源项目 [MiniBMS by ks-santosh](https://github.com/ks-santosh/MiniBMS) 的个人学习项目。

本项目的核心目标是深入理解并实践汽车电子行业主流的**模型化开发(MBD, Model-Based Design)**核心流程，包括：
* Simulink/Stateflow 建模
* 使用 Embedded Coder 自动生成C代码
* 对模型和生成代码进行软件在环(SIL)测试

## 2. 项目结构

MiniBMS/: 存放原始Simulink模型文件 (.slx, .m等)，其中也包含了Simulink自动生成的C代码目录 (BATTERY_MANAGEMENT_SYSTEM_grt_rtw/)。

LICENSE: 本项目所遵循的MIT开源许可证文件。

README.md: 你正在阅读的这个项目说明文件。

## 3. 核心实践内容

* **模型解析:** 深入学习了 `MiniBMS.slx` 中关于SOC估算、均衡控制、故障诊断等模块的建模方法和逻辑实现。
* **代码生成:** 成功配置 `Embedded Coder`，从Simulink模型自动生成了符合嵌入式标准的C代码，存放于 `BATTERY_MANAGEMENT_SYSTEM_grt_rtw` 目录中。
* **在环测试:** 搭建了**软件在环(SIL)**测试环境，对生成的C代码进行回环测试，以验证模型核心算法的正确性与可靠性。
* **学习与分析:** 对比了自动生成的代码与传统手写代码的风格与结构，加深了对MBD开发流程优势的理解。

## 4. 致谢

感谢 [ks-santosh](https://github.com/ks-santosh) 开源了优秀的 `MiniBMS` 项目，为本次学习实践提供了宝贵的资源。
