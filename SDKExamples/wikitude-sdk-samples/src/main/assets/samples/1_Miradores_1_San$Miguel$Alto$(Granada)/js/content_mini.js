var project = {"id":40826,"targetCollections":{"V2":{"targetCollectionUrl":"wtc/targetcollections_4.0.x.wtc"},"V3":{"targetCollectionUrl":"wtc/targetcollections_4.1.x.wtc"},"V1":{"targetCollectionUrl":"wtc/targetcollections_3.x.wtc"},"targetCollectionThumbnailUrl":"http://s3-eu-west-1.amazonaws.com/studio-live/869581/datasets/98c74554-27f3-452f-b713-0372bd354af7/dataset_gallery.png"},"targetCollectionUrl":"wtc/targetcollections.wtc","lastLocallyStored":"2016-04-14T18:08:42.016Z","targets":[{"id":"0.32749703808545383","augmentations":[{"textColor":{"g":0,"b":0,"r":0,"a":1},"text":"Algo","backgroundColor":{"g":255,"b":255,"r":255,"a":1},"zoom":1,"width":6.15234375,"type":"Text","zOrder":1000,"id":"bp_aug_2638595","height":6.25,"rotation":0,"name":"bp_aug_2638595","opacity":100,"clickUrl":"","textStyle":"","y":25.892301708409747,"x":11.78817014418737},{"textColor":{"g":0,"b":0,"r":0,"a":1},"text":"Text","backgroundColor":{"g":255,"b":255,"r":255,"a":1},"zoom":1,"width":5.6640625,"type":"Text","zOrder":1001,"id":"bp_aug_1690077","height":6.25,"rotation":0,"name":"bp_aug_1690077","opacity":100,"clickUrl":"","textStyle":"","y":10,"x":10},{"textColor":{"g":0,"b":0,"r":0,"a":1},"text":"Algo","backgroundColor":{"g":255,"b":255,"r":255,"a":1},"zoom":1,"width":6.15234375,"type":"Text","zOrder":1002,"id":"bp_aug_894143","height":6.25,"rotation":0,"name":"bp_aug_894143","opacity":100,"clickUrl":"","textStyle":"","y":53.280350004298484,"x":72.72352090072107}],"scaleFactor":0.7099609375,"active":true,"label":"sanmiguel","zoomFactor":60,"size":{"height":576,"width":1024}}]};

if ( __SDK.checkVersion({minSDKVersion: {ios: "3.2", android: "3.2"}/*, requiredFeatures: ["3d"]*/}) ) {
    var converter = new blueprint.Converter(null, {report : false});
    converter.convertProject(project);
}