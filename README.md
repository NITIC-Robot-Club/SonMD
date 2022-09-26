# SonMD

## 使い方

### インスタンスの作成

```cpp
#include "sonMD.h"

sonMD name(
  pin1,pin2, // 割り当てるpin名
  period     // 周期
)
```

pin は PWM に対応しているピンを割り当ててください。
period には周期を割り当ててください、

### PWM 出力

MD の性質上 0 に近ければ回転数は多くなり、1 に近ければ少なくなっていきます。
PWM 制御において、0.1s ごとに指定した割合分増減するようになっています。

```cpp
name::move_p1(
  displacement  // 0.1sごとに増加する割合
  target        // 目標値
);
//move_p2でも同

name::stop(); // 最大1sかけて止まります。
```
