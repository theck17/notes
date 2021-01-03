---
title: 'bootstrap'
date: 2020-05-06 00:37:43
tags: [Django]
published: true
hideInList: false
feature: /post-images/bootstrap.jpg
isTop: false
---
```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>表格制作</title>
    <meta name="viewport" content="width=device-width,initial-scale=1,minimum-scale=1,maximum-scale=1,user-scalable=no" />
    <!-- <link rel="stylesheet" type="text/css" href="css/style.css" /> -->
    <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css" />
    <script src="js/jquery-1.10.2.js"></script>
    <script src="js/bootstrap.min.js" type="text/javascript" charset="utf-8"></script>
    <!-- <script src="js/bootbox.min.js"></script> -->
</head>
<body>
    <div style="height: 100px;">
        <div class="col-xs-2">
            <ul class="nav nav-tab vertical-tab" role="tablist" id="vtab">
                <li role="presentation" class="active">
                    <a href="#tab_created" aria-controls="home" role="tab"
                       data-toggle="tab">我创建的</a>
                </li>
                <li role="presentation">
                    <a href="#tab_related " aria-controls="inbox" role="tab"
                       data-toggle="tab">和我有关</a>
                </li>
            </ul>
        </div>
            <div class="tab-content vertical-tab-content col-xs-10">
                    <div role="tabpanel" class="tab-pane active" id="tab_created">
                        <div class="container">
                            <h4 class="page-header">我创建的群组</h4>
                            <!--tabs-left:选项卡在左边显示  -->
                            <div class="tabbable">
                                <!--nav-pills，nav-tabs，nav-stacked :改变选项卡的样式-->
                                <ul class="nav nav-tabs">
                                    <li class="active"><a href="#tab1" data-toggle="tab">群组1</a>
                                    </li>
                                    <li><a href="#tab2" data-toggle="tab">群组2</a>
                                    </li>
                                </ul>
                                <!-- 选项卡相对应的内容 -->
                                <div class="tab-content">
                                    <div class="tab-pane active" id="tab1">
                                        <div class="container">
                                            <table class="table table-hover table-bordered">
                                                <thead>
                                                    <tr>
                                                        <th>
                                                            IP
                                                        </th>
                                                        <th>
                                                            hostname
                                                        </th>
                                                        <th>
                                                            责任人
                                                        </th>
                                                        <th>
                                                            创建时间
                                                        </th>
                                                    </tr>
                                                </thead>
                                                <tbody>
                                                    <tr>
                                                        <td>
                                                            10.121.186.224
                                                        </td>
                                                        <td>
                                                            hostname
                                                        </td>
                                                        <td>
                                                            wwx803628
                                                        </td>
                                                        <td>
                                                            01/04/2020
                                                        </td>
                                                    </tr>
                                                </tbody>
                                            </table>
                                        </div>
                                    </div>
                                    <div class="tab-pane" id="tab2">
                                        <div class="container">
                                            <table class="table table-hover table-bordered">
                                                <thead>
                                                    <tr>
                                                        <th>
                                                            IP
                                                        </th>
                                                        <th>
                                                            hostname
                                                        </th>
                                                        <th>
                                                            责任人
                                                        </th>
                                                        <th>
                                                            创建时间
                                                        </th>
                                                    </tr>
                                                </thead>
                                                <tbody>
                                                    <tr>
                                                        <td>
                                                            10.121.186.224
                                                        </td>
                                                        <td>
                                                            hostname
                                                        </td>
                                                        <td>
                                                            wwx803628
                                                        </td>
                                                        <td>
                                                            01/04/2020
                                                        </td>
                                                    </tr>
                                                </tbody>
                                            </table>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div role="tabpanel" class="tab-pane" id="tab_related">
                        <div class="container">
                            <h4 class="page-header">和我有关的群组</h4>
                            <!--tabs-left:选项卡在左边显示  -->
                            <div class="tabbable">
                                <!--nav-pills，nav-tabs，nav-stacked :改变选项卡的样式-->
                                <ul class="nav nav-tabs">
                                    <li class="active"><a href="#tab3" data-toggle="tab">群组3</a>
                                    </li>
                                    <li><a href="#tab4" data-toggle="tab">群组4</a>
                                    </li>
                                </ul>
                                <!-- 选项卡相对应的内容 -->
                                <div class="tab-content">
                                    <div class="tab-pane active" id="tab3">
                                        <div class="container">
                                            <table class="table table-hover table-bordered">
                                                <thead>
                                                    <tr>
                                                        <th>
                                                            IP
                                                        </th>
                                                        <th>
                                                            hostname
                                                        </th>
                                                        <th>
                                                            责任人
                                                        </th>
                                                        <th>
                                                            创建时间
                                                        </th>
                                                    </tr>
                                                </thead>
                                                <tbody>
                                                    <tr>
                                                        <td>
                                                            10.121.186.224
                                                        </td>
                                                        <td>
                                                            hostname
                                                        </td>
                                                        <td>
                                                            wwx803628
                                                        </td>
                                                        <td>
                                                            01/04/2020
                                                        </td>
                                                    </tr>
                                                </tbody>
                                            </table>
                                        </div>
                                    </div>
                                    <div class="tab-pane" id="tab4">
                                        <div class="container">
                                            <table class="table table-hover table-bordered">
                                                <thead>
                                                    <tr>
                                                        <th>
                                                            IP
                                                        </th>
                                                        <th>
                                                            hostname
                                                        </th>
                                                        <th>
                                                            责任人
                                                        </th>
                                                        <th>
                                                            创建时间
                                                        </th>
                                                    </tr>
                                                </thead>
                                                <tbody>
                                                    <tr>
                                                        <td>
                                                            10.121.186.224
                                                        </td>
                                                        <td>
                                                            hostname
                                                        </td>
                                                        <td>
                                                            wwx803628
                                                        </td>
                                                        <td>
                                                            01/04/2020
                                                        </td>
                                                    </tr>
                                                </tbody>
                                            </table>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
            </div>
    </div>

</body>
</html>


```