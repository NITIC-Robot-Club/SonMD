# SonMD

## 使い方

### インスタンスの作成
```cpp
#include "sonMD.h"

sonMD name(pin1,pin2)
```

pinはPWMに対応しているピンを割り当ててください。

### PWM出力

PWM制御において、0.1sごとに指定した割合分増加するようになっています。

```cpp
name::move_p1(
  value  // 0.1sごとに増加する割合
  target // 目標値
 )
//move_p2でも同

name::stop(); // 最大1sかけて止まります。
```
