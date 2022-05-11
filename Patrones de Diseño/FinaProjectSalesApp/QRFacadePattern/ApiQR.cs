using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZXing;
using ZXing.Common;
using System.Drawing.Imaging;
using System.Net;
using Newtonsoft.Json.Linq;
using System.IO;
using System.Drawing;

namespace FinaProjectSalesApp
{
    class ApiQR
    {
        public ApiQR() { }
        public string decode(string fileName)
        {
            Bitmap bm = new Bitmap(fileName);
            var reader = new BarcodeReader(null, null, ls => new GlobalHistogramBinarizer(ls))
            {
                Options = new DecodingOptions
                {
                    TryHarder = true, TryInverted=true
                }
            };
            var result = reader.Decode(bm);
            bm.Dispose();
            if (result == null)
            {
                Console.WriteLine("Decode failed.");
                return "";
            }
            Console.WriteLine("Result: {0}", result.Text);
            return result.Text;
        }
        public Stream request(string jsonString)
        {
            string url = "https://api.qrserver.com/v1/create-qr-code/?size=150x150&data=" + jsonString;
            WebRequest request = WebRequest.Create(url);
            request.Method = "GET";
            HttpWebResponse response = null;
            response = (HttpWebResponse)request.GetResponse();
            var stream = response.GetResponseStream();
            return stream;
        }
        public void saveBMPStream(Stream stream, string outputFileName)
        {
            if (File.Exists(outputFileName)){
                File.Delete(outputFileName);
            }
            Bitmap img = new Bitmap(stream);
            using (MemoryStream memory = new MemoryStream())
            {
                using (FileStream fs = new FileStream(outputFileName, FileMode.Create, FileAccess.ReadWrite))
                {
                    img.Save(memory, ImageFormat.Bmp);
                    byte[] bytes = memory.ToArray();
                    fs.Write(bytes, 0, bytes.Length);
                    fs.Dispose();
                }
            }
            // Mediator updates binnacle
            Singleton.GetInstance().mediator.updateBinnacle("New store image created");
            stream.Dispose();
            img.Dispose();
        }
        public string serializeStore(Store store)
        {
            return JsonConvert.SerializeObject(store);
        }
        public Store deserializeStore(string store)
        {
            return JsonConvert.DeserializeObject<Store>(store);
        }
    }
}
