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

#### コミット前に、自分のローカルを最新に適用(これ大事！)
```
git pull origin master
```
