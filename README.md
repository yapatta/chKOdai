# chKOdai
チームchKOdaiのICPC進捗

## 使い方

### 手順1
ローカルディレクトリにリモートレポジトリをクローンする
```
git clone git@github.com:yuziroppe/chKOdai.git
```

### 手順2
ディレクトリが作成されたか確認
/chKOdai

### gitコマンド

#### コミット前に、自分のローカルを最新に適用(これ大事！)
```
git pull origin master
```
ファイル編集前に必ずやるといい

#### コミットするファイルを指定
```
git add ./yahata-icpc (これは例です)
```

#### 指定したファイルをコミット
```
git commit -m "メッセージ"
```

#### ローカルのコミット内容をリモートに反映
```
git push origin master
```

### Tips

#### もし、pullする前にファイルを編集してしまった場合

##### 1)現在の編集内容を一時的に退避
```
git stash
```

##### 2)強制的にリモートの内容をローカルに適用
```
git fetch
git reset —-hard origin/master
```
リモートの内容をローカルで読み込み、リモートの内容を強制的にローカルに適用する、みたいなことをやってる

##### 3)退避した内容を現在の状態に適用
```
git stash pop
```

1)2)3)をやった後に、git addからやればうまくいくはず
