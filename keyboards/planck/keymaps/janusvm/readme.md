# JanusVM keymap for the OLKB Planck

This keymap is built to satisfy my personal needs, and as such provides:

* ANSI layout with support for Danish characters (Æ, Ø, Å)
* Consistency with my keycap set
* Programming-friendly placement of non-alphas that require at most one modifier or layer key to be held to reach
* A numpad with a large 0 key
* Emacs-friendly modifier key placement
* Easy access to my commonly used unicode characters
* RGB indication of layer status
* **TODO:** Switching between English and Danish mode, for providing a consistent layout if I have to use a computer set to take ISO Danish input

## Layers

### Base

![](https://i.imgur.com/2g3yH0G.png)

The base layer is mostly laid out like an ANSI QWERTY keyboard to match the keycaps I got.
This requires setting the system keyboard to US QWERTY, but since I mostly type in English anyway, I don't mind too much.

In terms of modifier and layer keys placement,

* A combined Ctrl/Esc key (Esc when tapped, Ctrl when held) sits where Caps Lock would usually be, as my Emacs + Evil workflow makes heavy use of both Ctrl and Esc
* I use both Shift keys when typing, so both are included, and the right Shift doubles as Enter when tapped
* Alt also features heavily in Emacs bindings, so I included both left and right Alt
* The Super (Windows) key is placed in the bottom right corner, as I don't use it all that much
* The Menu key (bottom row, third from left) is included as this key can be used as `M-x` in Emacs.
On togglable layers, it instead serves as an escape hatch to return to the base layer.
* Fn can be held with the left hand while using the numpad with the right
* I practically never use the right Ctrl, and the arrow keys are on HJKL, so the bottom right keys are tap-toggle access keys to unicode character layers

### Lower

![](https://i.imgur.com/ykOKKgG.png)

The lower layer's main feature are the Vim-like arrow keys on HJKL and the number row.
An additional Super and Alt keys are placed on the left side of the home row for certain keybindings such as Alt+[arrow keys].
The number row is there for familiarity, and some common Ctrl combinations are put on their respective keys.
This makes it so that I don't have to use my pinky for Ctrl and thereby shift my other fingers to "wrong" keys to input combinations.

Tab and Backspace are changed to Ctrl+Del and Ctrl+Backspace, respectively, and thus delete a word in the direction of the arrow on the keycap.

### Raise 

![](https://i.imgur.com/2jBJhEZ.png)

The Raise layer has standard special characters usually available on a regular keyboard as well as Danish, Shift-able letters Æ, Ø, and Å.
The characters are placed such that:

* Bracket delimiters (`() [] {} <>`) are available at the prime spots for paired keys.
While most editors automatically insert the closing bracket, I tend to use paired brackets in navigation-related keybindings, so I need opening and closing brackets next to each other.
* Several symbols (`! @ % & = \`) are at or close to their usual position on an ISO Danish keyboard 
* Certain symbols that pair up in Emacs and Vim-like keybindings (`^ $`, `# *`, and `= + -`) are placed together 
* Æ, Ø, and Å are on their usual keys

Additionally, this layer replaces Backspace with Delete and Tab with Esc, the latter specifically so that I can input Ctrl+Shift+Esc to get the Task Manager on Windows.

### Adjust

![](https://i.imgur.com/oe4sd2Y.png)

Keyboard settings and mouse keys layer, reached by holding Lower and Raise simoultaneously.
This layer also has some additional commands like Print Screen, Caps Lock, and media control keys.

**TODO:** the EN Mode and DA Mode keys currently do nothing.

### Fn/Numpad

![](https://i.imgur.com/P2Yquam.png)

Tap-toggle layer with F-keys and a numpad positioned such the 0 sits on the 2u space bar.

### Greek

![](https://i.imgur.com/pCBLx9V.png)

This layer simply has the Greek alphabet as Shift-able letters, mapped to their logical Latin equivalent.

### Symbols

![](https://i.imgur.com/g8861fn.png)

This layer features my most used special unicode characters.
They are placed such that most of them make sense mnemonically, i.e.

* `€ ® ™ ¥ ∞ √ ∇ © £ – —` have names that start with the letter of the key they occupy
* `∪ ∩ ∂ ∫ ¬ •` look a bit like the symbol of their key (some more than others)
* `² ≠ ° ← ↓ ↑ → × ∅` look a bit like symbols related to a secondary function of their key

### Emoji

![](https://i.imgur.com/ov1YNio.png)

This layer features quick access to my favourite unicode emoji, mainly so I can avoid using the built-in emoji pickers of Windows, Facebook, and Twitter (as they are either cumbersome or really slow to use).
While all modifier keys from the base layers have been assigned emoji, Space, Backspace, Lower, and Raise are kept for easier entry of multiple emoji.

The emoji are placed such that, as much as possible, the emoji of each column are somewhat related to each other:

* Happy faces 😄 😅 😂 😊
* Affectionate faces 😳 😍 🤪 🥺
* Sad faces 😩 😭 😔
* Flirty faces 😉 😘 😜 😏
* Sarcastic/teasing faces 🙄 🤨 😒
* Other faces 🤔 🙃 💩
* Status symbols ✅ ⚠ ⛔
* Hands 👉 👌 👏 👍 (🙏)
* Meme/injoke stuff 👀 🧠 🅱
* Symbols 💰 ✨ 💯 🔥
* Face modifers 💦 💕
