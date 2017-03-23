using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace mvc3.micro.music_store.Controllers
{
    public class StoreController : Controller
    {
        // GET: Store
        public string Index()
        {
            return "Hello from index";
        }

        //
        //Get: /store/Browse?genre=Disco
        public string Browse(string genre)
        {
            string msg = HttpUtility.HtmlEncode("store.browse, genre = " + genre);
            return msg;
        }

        //
        // Get: /store/Detail/5     can not implete for string as above func. 上面的string参数的方法不能用/Disco的形式
        // or   /store/detail?id=5  this is better.
        public string Detail(int id)
        {
            string msg = "store.detail, id = " + id;
            return msg;
        }
    }
}